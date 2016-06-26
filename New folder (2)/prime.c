#include<stdio.h>
#include<math.h>

int isprime(int a){
	int i,j;
	j=(int)sqrt(a);
	for(i=2;i<=j;i++){
		if(a%i==0)
		return 0;
	}
	return 1;
}
int max(int a,int b){
	return a>b?a:b;
}
void print_prime(int a,int b){
	int i,lp=-1;
	for(i=max(a,2);i<=b;i++){
		if(lp==i-1 && i!=3) {
			//
		}
		else if(isprime(i)){
			printf("%d\n",i);
			lp=i;
		}
	}
}
int main(){
	int t,m,n,i;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&m,&n);
		print_prime(m,n);
	}
	return 0;
}
