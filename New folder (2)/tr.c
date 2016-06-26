#include<stdio.h>
#include<math.h>
#define ll long long
#define N 5000001
int bin(ll int* a,ll int l,ll int h,ll int k){
	ll int mid;
	while(l<=h){
		mid = (l+h)/2;
		if(a[mid]==k){
			return mid;
		}
		if(a[mid]<k){
			l=mid+1;
		}
		else
		h=mid-1;
	}
	return -1;
}
int main(){
	ll int t,n,i,j,k,a,b,c,ind=0,arr[1000000];
	for(i=1;i<N;i++){
		for(j=1;j<i;j++){
			for(k=1;k<j;k++){
				if(((k*k)+(j*j))==(i*i)){
					arr[ind++]=i;
				}
			}
		}
	}
	ll int l = ind;
	printf("Length: %lld\n",l);
	scanf("%lld",&t);
	
	while(t--){
		scanf("%lld",&n);
		int flag=0;
		flag = bin(arr,0,l-1,n);
		if(flag!=-1) printf("YES\n");
		else printf("NO\n");
	}
}
