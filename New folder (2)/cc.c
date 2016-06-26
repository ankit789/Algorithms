#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int i,j,k,n,m,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int a[50],pred,postd,sum=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=2;i<=n-1;i++){
			pred=abs(a[i]-a[n-i+1]);
			if(a[i-1]%2==0 && a[i+1]%2==0){
				k=(a[i-1]+a[i+1])/2;
				postd=abs(k-a[n-i+1]);
				if(postd>pred)
					a[i]=k;
			}
		}
		for(i=1;i<=n/2;i++){
			sum=sum+abs(a[i]-a[n-i+1]);
		}
		printf("%d\n",sum);
	}
	return 0;
}
