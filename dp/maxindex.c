#include<stdio.h>
#include<stdlib.h>
void quicksort(int *x,int first,int last,int *index){
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         //index[pivot]=j;
         index[j]=pivot;
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1,index);
         quicksort(x,j+1,last,index);

    }
}
int max(int a,int b){
    return a>b?a:b;
}
int search(int *a,int x,int l){
	int i;
	for(i=0;i<l;i++){
		if(a[i]==x)
		return i;
	}
}
int maximumGap(const int* A, int n1) {
    int i,j,index[n1],x[n1],maxind=-1,maxindex=-1,prevind[n1];
    for(i=0;i<n1;i++){
    	prevind[i]=A[i];
    }
	quicksort(A,0,n1-1,index);
    
    for(i=0;i<n1;i++){
    	index[i]=search(prevind,A[i],n1);
        printf("%d ",index[i]);
    }
    for(i=n1-1;i>=0;i--){
        maxind=max(maxind,index[i]);
        x[i]=maxind;
    }
    for(i=0;i<n1;i++)
    maxindex=max(maxindex,x[i]-index[i]);
    
    return maxindex;
}
int main(){
	const int a[]={7,2,11,5,27,6},n=6;
	printf("%d",maximumGap(a,n));
}
