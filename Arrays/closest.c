#include<stdio.h>
#include<limits.h>
int main(){
	int i,p,q,n,x;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&x);	
	int l=0,r=n-1,diff=INT_MAX;
	while(l<r){
		if((abs(a[l]+a[r])-x)<diff){
			diff=abs(a[l]+a[r]-x);
			p=l;q=r;
		}
		if(a[l]+a[r]>x)
		r--;
		else
		l++;
	}
	printf("Pair: %d %d\n",a[p],a[q]);
	return 0;
}
