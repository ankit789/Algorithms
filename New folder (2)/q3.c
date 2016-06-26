#include<stdio.h>
#include<math.h>
int calc(int *a,int *vis,int n,int curr,int flag,int s,int k){
	int i,j,sum;
	if(s==0){
		for(;curr<n;curr++){
			vis[curr]=0;
		}
	}
	if(curr==n){
		sum=0;
		for(j=0;j<n;j++){
			if(vis[j]){
				sum+=a[j];
			}
		}
		if(sum==k) return 1;
		else return 0;
	}
	
	if(flag && vis[curr-1]==1){
		vis[curr]=1;
		calc(a,vis,n,curr+1,flag,s-1,k);
		vis[curr]=0;
		calc(a,vis,n,curr+1,flag,s,k);
	}
	else if(flag==0){
		vis[curr]=1;
		flag=1;
		calc(a,vis,n,curr+1,flag,s-1,k);
		
		vis[curr]=0;
		flag=0;
		calc(a,vis,n,curr+1,flag,s,k);
	}else{
		calc(a,vis,n,curr+1,flag,s,k);
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
		
		for(i=0;i<s;i++){
			for(i=0;i<n;i++){
				
			}
		}
		
	}
	return 0;
}
