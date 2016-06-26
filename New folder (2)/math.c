#include<stdio.h>
#include<math.h>
void printarr(int *a,int n){
	int i;
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	printf("\n");
}
int calc(int *a,int *vis,int n,int curr,int flag,int s,int x,int k,int k1){
	int i,j,sum;
	if(k==0){
		s--;
		k=k1;
	}
	if(s==0){
		while(curr<n){
			vis[curr++]=0;
		}
	}
	
	if(curr==n){
		sum=0;
		printarr(vis,n);
		for(j=0;j<n;j++){
			if(vis[j]){
				sum+=a[j];
			}
		}
		if(sum==x) return 1;
		else return 0;
	}
	
	if(flag && vis[curr-1]==1){
		vis[curr]=1;
		calc(a,vis,n,curr+1,flag,s-1,x,k-1,k1);
		vis[curr]=0;
		calc(a,vis,n,curr+1,flag,s,x,k,k1);
	}
	else if(flag==0){
		vis[curr]=1;
		flag=1;
		calc(a,vis,n,curr+1,flag,s-1,x,k-1,k1);
		
		vis[curr]=0;
		flag=0;
		calc(a,vis,n,curr+1,flag,s,x,k,k1);
	}else{
		calc(a,vis,n,curr+1,flag,s,x,k,k1);
	}
}
int main(){
	int i,j,s,k,n,q,x;
	scanf("%d%d",&n,&k);
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	scanf("%d",&q);
	while(q--){
		int *vis;
		scanf("%d%d",&s,&x);
		vis=(int*)calloc((n),sizeof(int));
		
		vis[0]=1;
		int curr=0;
		int flag=1;
		if(k==1) s--;
		int p = calc(a,vis,n,curr+1,flag,s,x,k,k);
		
		vis[0]=0;
		flag=0;
		if(k==1) s++;
		int q = calc(a,vis,n,curr+1,flag,s,x,k,k);
		
		if(p||q){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
