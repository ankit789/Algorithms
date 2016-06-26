#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long

int mat[1000][1000];

int arc=0;
int count_min_col(ll int m,ll int n,int mat[][n],int *index){
	ll int i,j,min=INT_MAX,ind;
	for(i=0;i<n;i++){
		
		if(min>sum){
			min = sum;
			ind = i;
		}
	}
	*index = ind;
	return min;
}
int count_min_row(ll int m,ll int n,int mat[][n],int *index){
	ll int i,j,min=INT_MAX,ind;
	for(i=0;i<m;i++){
		ll int sum=0;
		for(j=0;j<n;j++){
			sum+=mat[i][j];
		}
		if(min>sum){
			min = sum;
			ind = i;
		}
	}
	*index = ind;
	return min;
}
int main(){
	ll int n,t,m,u,a,b,i,j,count=0;
	scanf("%lld%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%d",&mat[i][j]);
				if(mat[i][j]<0){
					count++;
				}
			}
		}
		if(count==1){
			
		}else{
			int r_ind,c_ind,flag;
			int min_row = count_min_row(m,n,mat,&r_ind);
			int min_col = count_min_col(m,n,mat,&c_ind); 
			
			int flag = min_row<min_col?flag=1:flag=0;
			
			
		}		
	}
	return 0;
}
