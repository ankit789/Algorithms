#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int *sol;
void print(int *a,int n){
	int i;
	printf("\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
int tow(int *a,int i,int n,int sum,int csum,int *min,int *b,int k){
	if(i==n)
	return;
	int j;
	if(n/2-k > n-i)
	return;
	
	tow(a,i+1,n,sum,csum,min,b,k);
	
	k++;
	b[i]=1;
	csum+=a[i];
//	printf("Current sum after including %d is %d\n",a[i],csum+a[i]);
	
	
	if(k==n/2){
		if(abs(sum/2-csum)<*min){
			for(j=0;j<n;j++){
				sol[j]=b[j];
			}
			//print(sol,n);
			*min=abs(sum/2-csum);
			//printf("Min: %d\n",*min);
		}
	}
	else{
		
	//	printf("Current sum excluding %d is %d\n",a[i],csum-a[i]);
		tow(a,i+1,n,sum,csum,min,b,k);
	}
	b[i]=0;
}
int main(){
	int i,j,n,a[100],sum=0,*b;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	printf("Sum of array elements: %d\n",sum);
	sol=(int*)calloc(n,sizeof(int));
	b=(int*)calloc(n,sizeof(int));
	int min=INT_MAX;
	tow(a,0,n,sum,0,&min,b,0);
	
	printf("Sol: ");
	print(sol,n);
	return 0;
}
