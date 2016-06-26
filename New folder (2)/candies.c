#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	long long int i,j,t,n,sum,h;
	scanf("%lld",&t);
	while(t--){
		sum=0;
		h=-1;
		scanf("%lld",&n);
		long long int a[n];
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);
			sum+=a[i];
			h=max(h,a[i]);
		}
	//	printf("%d ",h);
		//int et=ceil(sum/n)*n;
		long long int diff=(h*n)-sum;
		printf("%lld\n",diff);
	}
	return 0;
}
