#include<stdio.h>
#include<stdlib.h>
#define ll long long 
int main(){
	ll int i,j,n,t,count;
	scanf("%lld",&t);
	while(t--){
		count=0;
		scanf("%lld",&n);
		ll int a[n];
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		ll int prev = 0;
		for(i=1;i<n;i++){
			if(a[i]<a[i-1]){
				ll int p=i;
				ll int x = i-prev;
				ll int t = (x*(x-1))/2;
				count+=t;
				prev=i;
			}
		}
		if(a[i-1]>a[i-2] && n>1){
			ll int x = i-prev;
			ll int t = (x*(x-1))/2;
			count+=t;
		}
		count+=n;
		printf("%lld\n",count);
	}
}
