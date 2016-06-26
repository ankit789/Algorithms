#include<stdio.h>
#include<stdlib.h>
int max(int a,int b){
	return a>b?a:b;
}

void print(int *a,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

int main(){
	int n,i,j,k,*a,*b,*c;
	scanf("%d",&n);
	a=(int*)calloc(n,sizeof(int));
	b=(int*)calloc(n,sizeof(int));
	c=(int*)calloc(n,sizeof(int));
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	b[0]=a[0];
	for(i=1;i<n;i++){
		b[i]=b[i-1]^a[i];
	}
	c[n-1]=a[n-1];
	for(i=n-2;i>=0;i--){
		c[i]=c[i+1]^a[i];
	}
	
	//print(b,n);
	//print(c,n);
	
	int x,y,maxm=-1,max_x=-1,max_y=-1,max_xor1=-1,max_xor2=-1;
	for(i=0;i<n-1;i++){
		for(j=0;j<=i;j++){
			max_xor1=max(max_xor1,b[j]);
			x=max(max_xor1,a[j]);
			if(max_x<x)
			max_x=x;
		}
		for(j=i+1;j<n;j++){
			max_xor2=max(max_xor2,c[j]);
			y=max(max_xor2,a[j]);
			if(max_y<y)
			max_y=y;
		}
		
		if(maxm<(max_x+max_y)){
			maxm=max_x+max_y;
		}
	}
	
	printf("%d\n",maxm);
}
