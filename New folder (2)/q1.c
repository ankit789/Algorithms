#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long
int arr[100001]={0};
void printarr(int n){
	int i;
	for(i=1;i<=n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main(){
	int n,u,a,b,i,j,p;
	scanf("%d%d",&n,&u);
	j =u;
	/*
	for(i=1;i<=n;i++){
		arr[i]=0;
	}
	*/
	while(u--){
		scanf("%d%d",&a,&b);
		p = b;
		i=1;
		while(p<=n){
			arr[p]+=1;
			p=a*i+b;
			i++;	
		}
		
	}
	printarr(n);
	return 0;
}
