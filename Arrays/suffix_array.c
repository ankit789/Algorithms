#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct suffix{
	int ind;
	int rank[2];
};
int *suffarr;
int cmp(const void *x,const void *y){
	struct suffix a = *(struct suffix*)x;
	struct suffix b=*(struct suffix*)y;
	if(a.rank[0]==b.rank[0]){
		return a.rank[1]<b.rank[1]?1:-1;
	}
	else{
		return a.rank[0]<b.rank[0]?1:-1;
	}
}
int create_suffix_array(char *text, int n){
	struct suffix s[n+1];
	int i,j;
	for(i=0;i<n;i++){
		s[i].ind=i;
		s[i].rank[0]=text[i]-'a';
		s[i].rank[1]=(i+1<n?text[i+1]-'a':-1);
	}
	qsort(s,n,sizeof(struct suffix),cmp);
	int index[n];
	for(i=4;i<2*n;i*=2){
		int pvrank=s[0].rank[0],rank=0;
		s[0].rank[0]=0;
		index[s[0].ind]=0;
		
		for(j=1;j<n;j++){
			if(s[j].rank[0]==pvrank && s[j].rank[1]==s[j-1].rank[1]){
				pvrank=s[j].rank[0];
				s[j].rank[0]=pvrank;
			}else{
				pvrank=s[j].rank[0];
				s[j].rank[0]=++rank;
			}
			index[s[j].ind]=j;
			
		}
		for(j=0;j<n;j++){
			s[j].rank[1]=((s[j].ind+(i/2))<n?s[index[(s[j].ind+(i/2))]].rank[0]:-1);
		}
		
		qsort(s,n,sizeof(struct suffix),cmp);
	}
	suffarr=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		suffarr[i]=s[i].ind;
	}
}
int main(){
	char s[1000];
	int i;
	gets(s);
	int l=strlen(s);
	create_suffix_array(s,l);
	printf("\nSuffix Array: ");
	for(i=0;i<l;i++){
		printf("%d\n",suffarr[i]);
	}
}
