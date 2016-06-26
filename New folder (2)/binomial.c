#include<stdio.h>

int main(){
	int t,n,i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int a[n];
		a[0]=1;
		printf("%d ",a[0]);
		for(i=1;i<n;i++){
			a[i]=(a[i-1]*(n-i))/(i);
			printf("%d ",a[i]);
		}
		printf("\n");
	}
}
