#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ll long long
#define N 1000000007
#define M 1000001
/*
ll int calc(ll int n,ll int k,ll int res){
	
	if(k>1){
		ll int prev = calc(n-1,k-1,res);
		ll int s = calc(n,k-1,res);
		res+=ceil((s*prev)/(s-prev));
	}else if(k==1){
		return n;
	}
	return res;
}
*/
ll int gcd(ll int a,ll int b){
  if (b == 0){
	if(a==0) return 1;
	return a; 		
  }
  return gcd(b, a%b);
}
ll int c[M],d[M];
ll int mat[M];
int main(){
	ll int n,k,a,b,m,t,i,ans,y=1;
	scanf("%lld",&t);
	scanf("%lld%lld",&n,&k);
	scanf("%lld%lld%lld",&a,&b,&m);
	
	for(i=1;i<t;i++)
	scanf("%lld",&c[i]);
	for(i=1;i<t;i++)
	scanf("%lld",&d[i]);
	
	
	while(t--){
		//printf("n: %lld k: %lld\n",n,k);
		
		//mat[1]=n;
		mat[1]=1;
		for(i=2;i<=k;i++){
			mat[i]=((mat[i-1]*(n-i+1))%N)/(i-1);
			//printf("f[%lld,%lld]: %lld\n",n,i,mat[i]);
		}
		for(i=1;i<=k;i++){
			mat[i]*=n;
		}
		/*
		printf("Matrix\n");
		for(i=1;i<=k;i++)
		printf("%lld ",mat[i]);
		printf("\n");
		*/
		//for()
		//printf("Calculating LCM\n");
		ans=mat[1]%N;
		for(i=2;i<=k;i++){
			if(ans==0)
			break;
			ans = ((((ans%N)*(mat[i]%N))%N)/((gcd(ans,mat[i]))))%N;
			//printf("%lld: ",ans);
		}
		//printf("LCM: %lld\n",ans);
		//printf("\nAns: ");
		printf("%lld\n",ans);
		
		if(t){
			n = 1+(a*ans+c[y])%m;
			k= 1+(b*ans+d[y])%n;
			y++;
		}
	}
	
	//int mat[n][n];
	return 0;
}
