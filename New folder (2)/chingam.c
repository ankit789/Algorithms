#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int t,n,a[101],i,j;
	scanf("%d",&t);
	while(t--){
		int count=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int l,r,e;
		l=a[0];
		r=a[n-1];
		e=n-1;
		i=1;
		while(i<e){
			if(a[e]>r){
				r=a[e];
				e--;
			}
			else if(a[i]<l){
				l=a[i];
				i++;
			}
			else{
				
			}
		}
	}	
	return 0;
}
