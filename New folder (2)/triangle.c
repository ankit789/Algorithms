#include<stdio.h>
#include<math.h>
#define ll long long
int main(){
	ll int t,n,i,j;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		ll int flag=0;
		ll int p = floor(sqrt((n*n)-1));
		//printf("p: %lld\n",p);
		for(i=p;i>=1;i--){
			ll int q = (n*n)-(i*i);
			ll int k = sqrt(q);
			ll int z = k;
			k=k*k;
			//printf("%lld\n",k);
			//printf("%f\n",k);
			//ll int x = (ll int)k;
			if( k==q ){
				//printf("%lld %lld %lld\n",i,z,n);
				flag=1;
				break;
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
}
