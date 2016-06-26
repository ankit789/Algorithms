#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int i,n;
	scanf("%d",&n);
	int a[n],x[n];
	long int sum=0;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		x[i]=1;
	}
	for(i=1;i<n;i++){
		if(a[i]>a[i-1])
		x[i]=x[i-1]+1;
		else if(a[i]<a[i-1] && a[i]>a[i+1] && i<n-1)
		x[i]=x[i+1]+1;
		else if(a[i]==a[i-1])
		x[i]=x[i-1];
		sum+=x[i];
	}
	printf("%ld",sum+1);
	return 0;
}
