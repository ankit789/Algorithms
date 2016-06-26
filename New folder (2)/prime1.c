#include<stdio.h>
#include<math.h>
#define ll long long
int isprime(long long int a){
	long long int i,j;
	 j=(ll int)sqrt(a);
	if(a<2) return 0;
	if(a==2 || a==3) return 1;
	for(i=2;i<=j;i++){
		if(a%i==0)
		return 0;
	}
	return 1;
}
ll int digits(long long int a){
	long long int s=0;
	while(a>0){
		s+=a%10;
		a=a/10;
	}
	return s;
}

int binary(ll int A[], ll int l, ll int r, ll int key)
{
    int m;
    while( l <= r ){
        m = l + (r-l)/2;
        if( A[m] == key)
            return m;
        if( A[m] < key)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
int main(){
	long long int i,j,l,n,t,d,a,b,sum,ind=0;
	long long int prime[100000];
	scanf("%lld",&n);
	for(i=1;i<=1000000;i++){
		if(isprime(i)){
			prime[ind++]=i;
		}
	}
	l=ind;
	while(n--){
		sum=0;
		scanf("%lld%lld",&a,&b);
		for(i=a;i<=b;i++){
			if(binary(prime,0,l-1,i)!=-1){
				sum+=digits(i);
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
