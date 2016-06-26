#include<stdio.h>
#include<string.h>
int main(){
	
	int *visited;
	int i,j,n,l,cur_len=0,max_len=0;
	char str[50];
	gets(str);
	
	visited=(int)calloc(26,sizeof(int));
	for(i=0;str[i]!='\0';i++){
		if(visited[str[i]-'a']==0){
			visited[str[i]-'a']=1;
			cur_len++;
			
		}
		else{
			if(cur_len>max_len){
				max_len=cur_len;
				cur_len=0;
			}
		}
	}
	
	return 0;
}
