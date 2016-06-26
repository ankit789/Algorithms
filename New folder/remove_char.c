#include<stdio.h>
#include<string.h>
void main(){
	char s1[20],s2[20];
	int *count,i,j;
	count=(int)calloc(256,sizeof(int));
	gets(s1);
	fflush(stdin);
	gets(s2);
	for(i=0;s2[i]!='\0';i++){
		count[s2[i]]++;
	}
	i=0;
	j=0;
	while(s1[i]!='\0'){
		if(count[s1[i]]==0){
			s1[j++]=s1[i];
		}
		i++;
	}
	s1[j]='\0';
	printf("\nFormatted String: ");
	puts(s1);
}
