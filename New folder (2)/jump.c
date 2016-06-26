#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define ll long long
int flag;
void calc(ll int* p,ll int* a,ll int* h,ll int n, ll int ind,ll int curr,ll int *max){
	ll int i,j=0;
	ll int temp = curr;
	if(ind==n-1){
		//*curr2=0;
		*max=temp<*max?temp:*max;
		//printf("Here: min: %lld\n",*max);
		flag=1;
		return ;
	}
	else{
		//ll int sind=ind;
		
		//flag=0;
		for(i=ind+1;i<n;i++){
			if(flag==1){
				temp=0;
				flag=0;
			}
			if(p[i]>p[ind]){
				j++;
				ll int x = h[i]-h[ind];
				x=x*x;
				temp+=(x+a[ind]);
			//	*curr2=temp;
				//printf("After jump from %lld to %lld curr: %lld and min: %lld\n",ind,i,temp,*max);
				calc(p,a,h,n,i,temp,max);
			}
			if(j)
			flag=1;
		}
	}
}
int main(){
	ll int n,i,j;
	scanf("%lld",&n);
	ll int p[n],a[n],h[n];
	
	for(i=0;i<n;i++)
	scanf("%lld",&p[i]);
	for(i=0;i<n;i++)
	scanf("%lld",&a[i]);
	for(i=0;i<n;i++)
	scanf("%lld",&h[i]);
	
	ll int min=INT_MAX;
	ll int curr=0;
	//ll int q = 0;
	//flag=0;
	calc(p,a,h,n,0,curr,&min);
	printf("%lld\n",min);
	return 0;
}
