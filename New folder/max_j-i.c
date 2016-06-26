#include<stdio.h>
int search(int *a,int s,int e){
	int i,j;
	if(s>=e)
	return 0;
	if(a[e]>a[s]){
		return e-s;
	}
	else{
		int b = search(a,s,e-1);
		if(!b){
			int b = search(a,s+1,e);
		}
		return b;
	}
}
int main(){
	int i,j,*a,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	int res = search(a,0,n-1);
	printf("%d\n",res);
	return 0;
}
