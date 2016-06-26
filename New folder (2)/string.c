#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int min(int a,int b){
	return a<b?a:b;
}
int main(){
	int i,j,t,a,b,c,l1,l2;
	char x[20000],u[20000];
	scanf("%d",&t);
	while(t--){
		int hash1[26],hash2[26];
		memset(hash1,0,sizeof(hash1));
		memset(hash2,0,sizeof(hash2));
		scanf("%s",x);
		scanf("%s",u);
		l1=strlen(x);
		l2=strlen(u);
		scanf("%d%d%d",&a,&b,&c);
		
		if((a+b)==0){
			printf("0\n");
			continue;
		}

		for(i=0;i<l1;i++){
			hash1[x[i]-'a']++;
		}
		for(i=0;i<l2;i++){
			hash2[u[i]-'a']++;
		}
		int diff=0;
		for(i=0;i<26;i++){
			//int min = min(hash1[i],hash2[i]);
			//hash1[i]-=min;
			//hash2[i]-=min;
			diff+=abs(hash1[i]-hash2[i]);
			
		}
		
		if(l1==l2){
			if(strcmp(x,u)==0){
				printf("0\n");
				continue;
			}
			else{
				if((a+b)<c){
					printf("%d\n",(a+b)*diff/2);
				}else{
					printf("%d\n",(c)*diff/2);
				}
			}
		}else{
			//int d=abs(l1-l2);
			//int r=l1>l2?l1-d:l2-d;
			if(l1>l2){
				int d= l1-l2;
				int res=d*a;
				diff=diff-d;
				res+=(min((a+b),c)*diff)/2;
				printf("%d\n",res);
			}
			else{
				int d= l2-l1;
				int res=d*b;
				diff=diff-d;
				res+=(min((a+b),c)*diff)/2;
				printf("%d\n",res);
			}
		}
	}
	return 0;
}
