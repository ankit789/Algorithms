#include<stdio.h>
#include<stdlib.h>
int find(int *a,int start,int end){
	if(start>end)
	return -1;
	
	if(start==end)
	return a[start];
	if(start+1==end)
	return a[start]>a[end]?a[start]:a[end];
	
	int mid=(start+end)/2;
	if(a[mid]>a[mid-1]&&a[mid]>a[mid]+1)
	return a[mid];
	else if(a[mid]<a[mid+1])
	return find(a,mid+1,end);
	else
	return find(a,start,mid-1);
}
int main(){
	int *a;
	int i,n;
	scanf("%d",&n);
	a=(int*)calloc(n,sizeof(int));
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	int max=find(a,0,n-1);
	
	printf("Req. element: %d\n",max);
	return 0;
	
}
