#include<stdio.h>
#include<string.h>
int main(){
	char s[100000],p;
	int i,j,n,t;
	scanf("%d",&t);
	while(t--){
		n=0;
		scanf("%s",s);
		p=s[0];
		for(i=1;s[i]!='\0';i++){
			if(s[i]==p){
				n++;
			}
			else{
				p=s[i];
			}
		}
		printf("%d\n",n);
	}
	return 0;
}
