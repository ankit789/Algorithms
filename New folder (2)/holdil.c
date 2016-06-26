#include<stdio.h>
#define N 1000000
int main(){
	long long int t;
	long long int i,s,l,h,mid,k;
	
	long long int a[N+1];
	a[0]=0;
	for(i=1;i<=N;i++){
		a[i]=a[i-1]+(i*i);
	}
	//printf("a[310722]: %lld\n",a[310722]);
	scanf("%lld",&t);
	while(t--){
		l=1;h=N;
		scanf("%lld",&s);
	//	printf("S: %lld\n",s);
		while(l<=h){
			mid=(l+h)/2;
			//printf("Mid: %lld a[mid]: %lld Low: %lld a[l]: %lld High: %lld a[h]: %lld\n",mid,a[mid],l,a[l],h,a[h]);
			if(a[mid]<s){
				//printf("Entering into a[mid] < n\n");
				k = mid;
				l=mid+1;
			}
			else if(a[mid]>s){
				//printf("Entering into a[mid] > n\n");
				h=mid-1;
				k=mid-1;
			}
			else{
				//printf("Entering into a[mid] == n\n");
				k=mid;
				break;
			}
		}
		
		printf("%lld\n",k);
	}
	return 0;
}
