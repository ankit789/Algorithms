#include<stdio.h>
#include<string.h>
int main(){
	int i,t,n,l;
	char s[10000];
	scanf("%d",&t);
	while(t--){
		n=0;
		int count[256]={0};
		scanf("%s",s);
		l=strlen(s);
		if(l%2==1){
			printf("%d\n",-1);
		}
		else{
			for(i=l/2;i<l;i++){
				count[s[i]]++;
			}
			for(i=0;i<l/2;i++){
				if(count[s[i]]!=0)
				count[s[i]]--;
			}
			for(i=0;i<256;i++){
				n+=count[i];
			}
			printf("%d\n",n);
		}
	}
	return 0;
}
