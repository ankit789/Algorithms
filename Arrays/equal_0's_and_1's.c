#include<stdio.h>
#include<stdlib.h>
void print(int *a,int n){
	int i;
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	printf("\n");
}
int main(){
	int i,j,*a,n,s,e;
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	for(i=0;i<n;i++){
		if(a[i]==0)
		a[i]=-1;
	}
	int max_size=-1,sum=0;
	int max=INT_MIN,min=INT_MAX;
	int sumleft[n];
	for(i=0;i<n;i++){
		sum+=a[i];
		sumleft[i]=sum;
		if(sumleft[i]==0){
			if(max_size<i+1){
				max_size=i+1;
				s=0;e=i;
			}
			
		}
		if(sumleft[i]>max)
		max=sumleft[i];
		if(sumleft[i]<min)
		min=sumleft[i];
		
	}
	printf("SumLeft: ");
	print(sumleft,n);
	
	int c=max-min+1;
	int hash[c];
	int temp_max=-1;
	for(i=0;i<c;i++){
		hash[i]=-1;
	}
	for(i=0;i<n;i++){
		if(hash[sumleft[i]-min]==-1){
			hash[sumleft[i]-min]=i;
		}
		else{
			int diff=i-hash[sumleft[i]-min];
			if(max_size<diff){
				max_size=diff;
				s=hash[sumleft[i]-min]+1;e=i;
			}
			printf("Diff: %d -- Max_Size: %d\n",diff,max_size);
		}
	}
	printf("Hash: ");
	print(hash,c);
		
	printf("Maxm Sub-Array: Size %d from %d to %d\n",max_size,s,e);
}
