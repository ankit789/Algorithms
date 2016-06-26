#include<stdio.h>
#include<string.h>
char up(char c,int k){
	char j;
	if(k>26){
		k=k%26;
	}
	if(c>='A' && c<='Z'){
		if(k>(c-'A')){
			int p = k-(c-'A');
			j='A'+(26-p);	
		}else{
			j=c-k;
		}
	}else{
		if(k>(c-'a')){
			int p = k-(c-'a');
			j='a'+(26-p);	
		}else{
			j=c-k;
		}
	}
	return j;
}
int main(){
	int i,j,n,t,k;
	char c;
	scanf("%d",&n);
	
	while(n--){
		c=getchar();
		int i;
		char s[100001];
		fgets(s,100001,stdin);
		//fflush(stdin);
		//c=getchar();
		scanf("%d",&k);
		int l=strlen(s);
		if(s[l-1]=='\n'){
			//printf("YES\n");
			s[l-1]='\0';
			l--;
		}
		for(i=0;i<l;i++){
			if((s[i]>='a' && s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
				//s[i]=s[i]-k;
				char c = up(s[i],k);
				s[i] =c ;
			}
		}
		printf("%s\n",s);
	}
}
