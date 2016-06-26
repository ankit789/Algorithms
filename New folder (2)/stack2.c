#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int t,n,i,j,len;
	scanf("%d",&t);
	while(t--){
		//struct node *stk = NULL;
		int size=0,flag=0,ind=0;
		scanf("%d",&n);
		int a[n],b[n];
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		memset(b,0,sizeof(b));
		int j = a[0];
		int l,r,c=0;
		b[0] = j;
		for(i=1;i<n;i++){
			int x=a[i];
			if(x>=b[c]){
				c++;
				b[c]=x;
			}
			else{	
				int mid;			
				l=0;r=c;
				while(l<r){
					mid=(l+r)/2;
					if(x<b[mid]){
						r=mid;
					}
					else{
						l=mid+1;
					}
				}
				b[l]=x;
			}
		}
		printf("%d ",c+1);
		for(i=0;i<=c;i++){
			printf("%d ",b[i]);
		}
		printf("\n");
	}
}
