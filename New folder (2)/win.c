#include<stdio.h>
#include<stdlib.h>
#define ll long long
ll int maxx(ll int a,ll int b){
	return a>b?a:b;
} 
int main(){
	ll int i,j,n,t;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		ll int w[n+1];
		char q[n],a[n];
		scanf("%s",q);
		scanf("%s",a);
		//printf("%s %s\n",q,a);
		
		ll int max=-1;
		for(i=0;i<=n;i++){
			scanf("%lld",&w[i]);
			//max=maxx(max,w[i]);
		}
		ll int count=0;
		ll int win=w[0];
		for(i=0;i<n;i++){
			if(q[i]==a[i]){
				count++;
				win=maxx(w[count],win);
			}
		}
		
		if(count==0){
			printf("%lld\n",w[0]);
		}
		else if(count==n){
			printf("%lld\n",w[n]);
		}
		else{
			printf("%lld\n",win);
		}
		
		
	}
	return 0;
}
