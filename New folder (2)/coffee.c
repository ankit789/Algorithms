#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int maxx(int a,int b){
	return a>b?a:b;
}
void coffee(int *a,int n,int d,int k,int m,int ld,int temp,int n1,int *max,int curr_max){
	int i;
	if(n1==n){
		return;
	}
	if(k==0){
		while(ld>0 && n1<n){
			curr_max+=(a[n1]*m);	
			ld--;
			n1++;
		}
		for(i=n1;i<n;i++){
			curr_max+=a[i];			
		}
		*max=maxx(*max,curr_max);
		//printf("At k=0 curr_max: %d max: %d\n",curr_max,*max);
		return;
	}
	if(ld>0){
		//curr_max+=(a[n1]*m);
		//int temp = ld;
		ld=d;
		//*max=maxx(*max,curr_max);
		//printf("Including %dth element curr_max:  %d max: %d\n",n1,curr_max,*max);
		coffee(a,n,d,k-1,m,ld,ld,n1+1,max,curr_max);
		//printf("Excluding %dth element max: %d\n",n1,*max);
		//curr_max-=(a[n1]*m);
		ld=temp;
		curr_max+=(a[n1]*m);
		*max=maxx(*max,curr_max);
		//printf("Excluding %dth element curr_max:  %d max: %d\n",n1,curr_max,*max);
		coffee(a,n,d,k,m,ld-1,ld-1,n1+1,max,curr_max);	
	}
	else{
		ld=d;
		//*max=maxx(*max,curr_max);
		//printf("Including %dth element curr_max:  %d max: %d\n",n1,curr_max,*max);
		coffee(a,n,d,k-1,m,ld,ld,n1+1,max,curr_max);
		//curr_max-=(a[n1]*m);
		ld=temp;
		curr_max+=a[n1];
		*max=maxx(*max,curr_max);
		//printf("Excluding %dth element curr_max:  %d max: %d\n",n1,curr_max,*max);
		coffee(a,n,d,k,m,ld-1,ld-1,n1+1,max,curr_max);
	}
}
int main(){
	int i,j,n,m,k,t,d;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&k,&d,&m);
		int a[n];
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int max=INT_MIN;
		coffee(a,n,d,k,m,0,0,0,&max,0);
		printf("%d\n",max);
	}
}
