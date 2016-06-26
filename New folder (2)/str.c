#include<stdio.h>
#include<string.h>

int main(){
	int i,j,n;
	scanf("%d",&n);
	char s1[n+1],s2[n+1];
	scanf("%s",s1);
	scanf("%s",s2);
	int l1,l2,l;
	l=strlen(s1);
	int p=0,q=0,r=0,count=0;
	//l2=strlen(s2);
	for(i=0;i<l;){
		p=i;
		int a=0;
		if(s1[0]==s2[i]){
			count++;
			i++;
			a++;
			while(s1[a]==s2[i]){
				if(i==n)
				break;
				a++;
				i++;
				
			}
			
		}
	}
}
