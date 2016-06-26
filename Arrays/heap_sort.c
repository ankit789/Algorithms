#include<stdio.h>
#include<stdlib.h>
#define SWAP(a,b) typeof(a) temp=a;a=b;b=temp;

int size;
void max_heapify(int *a,int i){
	int l,r,p;
	l=2*i+1;
	r=2*i+2;
	p=a[l]>a[r]?l:r;
	if(p<size && a[i]<a[p]){
		SWAP(a[i],a[p]);
		max_heapify(a,p);
	}
}
void buildHeap(int *a){
	int i;
	for(i=(size-1)/2;i>=0;i--){
		max_heapify(a,i);
	}
}
int main(){
	int i,n,*a;
	scanf("%d",&n);
	
	a=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	size=n;
	buildHeap(a);
	
	
	
	for(i=n-1;i>=1;i--){
		SWAP(a[0],a[i]);
		size--;
		max_heapify(a,0);
	}
	
	printf("Sorted: ");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}

}
