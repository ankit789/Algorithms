#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long
#define N 5000001
ll int a[N],b[N];
int main(){
	ll int t,n,i,j,k;
	
 
	for(i=1;i<=N;i++){
		a[i]=1;
		b[i]=0;
	}	
	
 
	for(i=2;i<=N;i++){
		if(a[i]==1){
			k=2;
			j=k*i;
			while(j<=N){
				a[j]=0;
				k++;
				j=k*i;
			}
		}
		if(a[i]==1 && i%4==1){
			//printf("primitive: %lld\n",i);
			b[i]=1;
			k=2;
			j=k*i;
			while(j<=N){
				b[j]=1;
				k++;
				j=k*i;
			}
		}
	}
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		if(b[n]){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
} 
