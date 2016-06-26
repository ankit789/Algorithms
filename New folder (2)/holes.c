#include<stdio.h>
#include<string.h>
int main(){
	int check[]={1,2,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0};
	
	int count,i,t;
	scanf("%d",&t);
	while(t--){
	char s[100];
	count=0;
	scanf("%s",s);
	int l = strlen(s);
	for(i=0;i<l;i++){
		count+=check[s[i]-65];
		//printf("Index: %d\n",s[i]-'A');
	}
	//printf("%c\n",s[i-1]);
	printf("%d\n",count);
	
	}
	
	return 0;
}
