#include<stdio.h>
struct ind{
	int i,j;
};
int main(){
	int t,n,count,i,j,p;
	scanf("%d",&t);
	while(t--){
		count=0;
		scanf("%d",&n);
		struct ind a[n*n+1];
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&p);
				a[p].i=i;
				a[p].j=j;
			}
		}
		for(i=1;i<n*n;i++){
			count+=(abs(a[i].i-a[i+1].i)+abs(a[i].j-a[i+1].j));
		}
		printf("%d\n",count);
	}
	return 0;
}
