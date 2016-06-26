#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int i,t,n,*a;
	scanf("%d",&t);
	while(t--){
		int curr_max=0,max_all=0,max_sum=0;
		scanf("%d",&n);
		a=(int*)calloc(n,sizeof(int));
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
		curr_max=max_all=a[0];
		if(a[0]>0)
		max_sum+=a[0];
		for(i=1;i<n;i++){
			if(a[i]>0){
				max_sum+=a[i];
			}
			if(a[i]<curr_max+a[i]){
				curr_max=curr_max+a[i];
			}
			else
			curr_max=a[i];
			if(max_all<curr_max)
			max_all=curr_max;
			
		}
		if(max_sum==0){
			max_sum=a[0];
			for(i=1;i<n;i++){
				max_sum=max_sum>a[i]?max_sum:a[i];
			}
		}
		printf("%d %d\n",max_all,max_sum);
	}
	return 0;
}
