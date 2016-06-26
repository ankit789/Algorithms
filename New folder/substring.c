#include<stdio.h>
#include<string.h>
int main(){
	char s1[1000000],s2[1000000];
	int i,j,t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%s",s1);
		fflush(stdin);
		scanf("%s",s2);
		int count[256]={0};
		for(i=0;s1[i]!='\0';i++){
			count[s1[i]]++;
		}
		for(i=0;s2[i]!='\0';i++){
			if(count[s2[i]]!=0)
				break;
		}
		if(s2[i]){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}
