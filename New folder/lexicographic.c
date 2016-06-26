#include<stdio.h>
#include<string.h>
int fact(int i){
	return (i<=1)?1:i*fact(i-1);
}
int store(int *count,char *s,int l){
	int i;
	for(i=0;i<l;i++){
		++count[s[i]];
	}
	for(i=1;i<256;i++){
		count[i]+=count[i-1];
	}
}
int update(int *count,int c){
	int i;
	for(i=c;i<256;i++){
		--count[i];
	}
}
int main(){
	int i,j,l,rank=1;
	int count[256]={0};
	char s[20];
	gets(s);
	l=strlen(s);
	j=fact(l);
	
	store(count,s,l);
	for(i=0;i<l;i++){
		j/=(l-i);
		rank+=count[s[i]-1]*j;
		update(count,s[i]);
	}
	
	printf("\nRank Of %s is: %d",s,rank);
	
	return 0;
}
