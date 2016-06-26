#include<stdio.h>
#include<string.h>
#include<math.h>
int abs(int a){
	return a>0?a:-a;
}
int max(int a,int b){
	return a>b?a:b;
}
int mod(int*a,int *b,int *c,int i,int n){
	
	int l=i;
	int r=n-i+1;
	int max_l=a[l],max_r=a[r];
	if(a[l-1]%2==0 && a[l+1]%2==0){
		max_l=(a[l-1]+a[l+1])/2;
	}
	if(a[r-1]%2==0 && a[r+1]%2==0){
		max_r=(a[r-1]+a[r+1])/2;
	}
	
	int diff1= abs(a[l]-max_r);
	int diff2=abs(max_l-a[r]);
	int diff3=abs(a[l]-a[r]);
	int diff4=abs(max_l-max_r);
	
	int p=max(diff1,diff2);
	int q=max(diff3,diff4);
	//l=max(max_l,a[l]);
	//r=max(max_r,a[r]);
	return max(p,q);
}
int main(){
	int i,j,n,t,a,b,c,max_l,max_r;
	scanf("%d",&t);
	while(t--){
		
		scanf("%d",&n);
		int a[n+1],b[n+1],c[n+1];
		for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
		
		for(i=1;i<=n/2;i++){
			b[i]=a[n-i+1];
		}
		int sum1=0,sum2=0,res;
		for(i=1;i<=n/2;i++){
			c[i]=abs(a[i]-b[i]);
		}
		sum1+=c[1];
		for(i=2;i<=n/2;i++){
			int l=a[i];
			int r=a[n-i+1];
			max_l=l;
			if(a[i-1]%2==0 && a[i+1]%2==0){
				max_l=(a[i-1]+a[i+1])/2;
			}
			int x1=abs(l-r);
			int x2=abs(max_l-r);
			if(x1>x2){
				res=x1;
			}
			else{
				res=x2;
				a[i]=max_l;
			}
			sum1+=res;
		}
		sum2+=c[1];
		for(i=n/2+1;i<=n-1;i++){
			int r=a[i];
			int l=a[n-i+1];
			max_r=r;
			if(a[i-1]%2==0 && a[i+1]%2==0){
				max_r=(a[i-1]+a[i+1])/2;
			}
			int x1=abs(l-r);
			int x2=abs(l-max_r);
			if(x1>x2){
				res=x1;
			}
			else{
				res=x2;
				a[i]=max_r;
			}
			sum2+=res;
		}
		int sum = max(sum1,sum2);
		printf("%d\n",sum);
	}
	return 0;
}
