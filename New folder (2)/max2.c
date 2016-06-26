#include<stdio.h>
#include<stdlib.h>
#define ll long long
int main(){
	ll int i,n,a,max1,max2;
	scanf("%lld",&n);
	scanf("%lld",&a);
	max1=max2=a;
	
	for(i=1;i<n;i++){
		scanf("%lld",&a);
		if(max1<a){
			if(max2<max1) max2=max1;
			max1=a;
		}
		else if(max2<a){
			max2=a;
		}
	}
	printf("%lld %lld\n",max1,max2);
	return 0;
}
