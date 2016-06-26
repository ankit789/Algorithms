#include<stdio.h>
#include<string.h>
/*
void cal_substr(int n,char res[][l],char *s){
	int i,j;
	
}
*/
void print_str(char *s,int i,int j){
	int k,n=0;
	for(k=i;k<=j;k++){
		printf("%c",s[k]);
		n++;
	}
	if(n)
	printf("\n");
}
int main(){
	char s[]="hello world";
	int i,j,l;
	l=strlen(s);
	
//	char res[l*((l+1)/2)][l];
//	cal_substr(l,res,s);
	for(i=0;i<l;i++){
		for(j=0;j<l;j++){
			print_str(s,i,j);
		}
	}
	return 0;
}
