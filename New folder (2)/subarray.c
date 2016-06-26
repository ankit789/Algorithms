#include<stdio.h>
#include<string.h>
int maxx(int a,int b){
	return a>b?a:b;
} 
int check(int *p,int *a,int n){
	int i,x=0,y=0;
	for(i=0;i<n;i++){
		if(a[i]){
			y++;
			x^=p[i];
		}
	}
	if(y)
	return x;
	else
	return -1;
}
void printarr(int *a,int n){
	int i;
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	printf("\n");
}
void calc(int *a,int *vis,int n,int curr,int flag,int curr_max,int *max,int k,int *count){
	int i;
	if(curr==n){
		//printarr(vis,n);
		curr_max=check(a,vis,n);
		if(curr_max<k && curr_max!=-1){
			printarr(vis,n);
			(*count)++;
		}
		*max=maxx(*max,curr_max);
		return;
	}
	if(flag && vis[curr-1]==1){
		//curr_max=curr_max^a[curr];
		vis[curr]=1;
		*max=maxx(curr_max,*max);
		calc(a,vis,n,curr+1,flag,curr_max,&max,k,count);
		
		//curr_max=curr_max^a[curr];
		vis[curr]=0;
		//*max=maxx(curr_max,*max);
		calc(a,vis,n,curr+1,flag,curr_max,&max,k,count);
	}
	else if(flag==0){
		//curr_max=curr_max^a[curr];
		vis[curr]=1;
		flag=1;
		*max=maxx(curr_max,*max);
		calc(a,vis,n,curr+1,flag,curr_max,&max,k,count);
		
		//curr_max=curr_max^a[curr];
		vis[curr]=0;
		flag=0;
		//*max=maxx(curr_max,*max);
		calc(a,vis,n,curr+1,flag,curr_max,&max,k,count);
	}else{
		calc(a,vis,n,curr+1,flag,curr_max,&max,k,count);
	}
	//return;
}
int main(){
	int i,j,n,t;
	scanf("%d",&t);
	while(t--){
		int k;
		scanf("%d%d",&n,&k);
		int *a,*vis;
		a=(int*)calloc((n),sizeof(int));
		vis=(int*)calloc((n),sizeof(int));		
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		
		int count=0;
		int max=-1;
		vis[0]=1;
		int curr=0;
		int flag=1;
		int curr_max = 0;
		//curr_max=curr_max^a[0];
		//max=curr_max;
		calc(a,vis,n,curr+1,flag,curr_max,&max,k,&count);
		
		vis[0]=0;
		flag=0;
		//curr_max=curr_max^a[0];
		calc(a,vis,n,curr+1,flag,curr_max,&max,k,&count);
		
		//printf("Max. XOR: %d Count %d\n",max,count);
		printf("%d\n",count);
		
	}
	return 0;
}
