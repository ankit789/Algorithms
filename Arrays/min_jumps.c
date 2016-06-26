#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
int min(int a,int b){
	return a>b?b:a;
}
int minjumps(int *a,int n){
	int *x=(int*)calloc(n,sizeof(int));
	int i,j;
	if(n==0||a[0]==0)
	return INT_MAX;
	
	x[0]=0;
	for(i=1;i<n;i++){
		x[i]=INT_MAX;
		for(j=0;j<i;j++){
			if (i <= j + a[j] && x[j] != INT_MAX){
                 x[i] = min(x[i], x[j] + 1);
                 break;
            }
		}
	}
	return x[n-1];	
}
int main(){
	int *a,i,n,*x;
	scanf("%d",&n);
	a=(int*)calloc(n,sizeof(int));
	
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	int no_of_jumps=minjumps(a,n);
	printf("Min. No of Jumps: %d\n",no_of_jumps);
	return 0;
}
