#include<stdio.h>
#include<stdlib.h>

int main(){
	int t,i;
	char x[10],y[10];
	scanf("%d",&t);
	while(t--){
		scanf("%s%s",x,y);
		for(i=0;x[i]!='\0'&&y[i]!='\0';i++){
			if(x[i]=='?'||y[i]=='?'){
				continue;
			}
			else if(x[i]!=y[i]){
				break;
			}
		}
		if(x[i]=='\0' && y[i]=='\0'){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}
