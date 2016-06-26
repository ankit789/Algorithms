#include<stdio.h>
#include<string.h>

int main(){
	int t,n,k,l,i,j,p;
	scanf("%d",&t);
	while(t--){
		char temp[6];
		scanf("%d%d",&n,&k);
		char dic[n][6];
		int val[n];
		memset(val, 0, sizeof(val));
		
		for(i=0;i<n;i++)
		scanf("%s",dic[i]);
		
		for(i=0;i<k;i++){
			scanf("%d",&l);
			for(j=0;j<l;j++){
				scanf("%s",temp);
				for(p=0;p<n;p++){
					if(strcmp(temp,dic[p])==0){
						val[p]=1;
						break;
					}
				}
			}
		}
		for(i=0;i<n;i++){
			if(val[i]) printf("YES ");
			else printf("NO ");
		}
		printf("\n");
	}
	return 0;
}
