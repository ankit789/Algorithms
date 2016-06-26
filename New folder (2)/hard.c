#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long

int mat[1000][1000];
int mat2[1000][1000];

int min(int a,int b){
	return a<b?a:b;
}
int main(){
	ll int n,t,m,u,a,b,i,j,k,count=0;
	scanf("%lld%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				scanf("%d",&mat[i][j]);
			}
		}
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				//ll int row_min,col_min;
				ll int curr_min,ov_min;
				
				curr_min = mat[i][0];ov_min=mat[i][0];
				for(k=1;k<j;k++){
					curr_min = min(mat[i][k], curr_min+mat[i][k]);
        			ov_min = min(ov_min, curr_min);
				}
				if(ov_min<0){
					mat2[i][j]+=ov_min;
				}
				
				if(j+1<n){
					curr_min = mat[i][j+1];ov_min=mat[i][j+1];
					for(k=j+2;k<n;k++){
						curr_min = min(mat[i][k], curr_min+mat[i][k]);
	        			ov_min = min(ov_min, curr_min);
					}
					if(ov_min<0){
						mat2[i][j]+=ov_min;
					}
				}
				
				
				curr_min = mat[0][j];ov_min=mat[0][j];
				
				for(k=1;k<i;k++){
					curr_min = min(mat[k][j], curr_min+mat[k][j]);
        			ov_min = min(ov_min, curr_min);
				}
				if(ov_min<0){
					mat2[i][j]+=ov_min;
				}
				
				if(i+1<m){
					curr_min = mat[i+1][j];ov_min=mat[i+1][j];
					for(k=i+2;k<m;k++){
						curr_min = min(mat[k][j], curr_min+mat[k][j]);
	        			ov_min = min(ov_min, curr_min);
					}
					if(ov_min<0){
						mat2[i][j]+=ov_min;
					}
				}			
			}
		}
		
		ll int min_ans = mat2[0][0];
		for(i=0;i<m;i<n){
			for(j=0;j<n;j++){
				if(mat2[i][j]<min_ans){
					min_ans = mat2[i][j];
				}
			}
		}
		
		printf("%lld\n",min_ans);
	}
	return 0;
}
