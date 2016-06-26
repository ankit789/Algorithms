#include<stdio.h>

int main(){
	long long int n,t;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		printf("%lld\n",(n/2)+1);
	}
}
