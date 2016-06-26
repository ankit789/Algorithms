#include<stdio.h>

int main(){
	int i,j,n;
	scanf("%d",&n);
	while(n>0){
		printf("%d ",n);
		n = n >> 1;
	}
	return 0;
}
