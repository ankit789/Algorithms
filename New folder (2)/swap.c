#include<stdio.h>
#include<string.h>

int main(){
	char s1[1000],s2[1000];
	int i,j,l1,l2;
	scanf("%s",s1);
	scanf("%s",s2);
	l1=strlen(s1);
	l2=strlen(s2);
	
	if(l1!=l2){
		printf("-1");
	}
	else{
		int c1=0,c2=0;
		for(i=0;i<l1;i++){
			if(s1[i]=='1')
			c1++;
			if(s2[i]=='1')
			c2++;
		}
		if(c1!=c2){
			printf("-1");
		}
		else{
			c1=0;
			for(i=0;i<l1;i++){
				if(s1[i]!=s2[i]){
					c1++;
				}
			}
			printf("%d",c1/2);
		}
		
	}
	return 0;
}
