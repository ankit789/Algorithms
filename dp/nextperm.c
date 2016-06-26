#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void quicksort(int *x,int first,int last){
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
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
}
void nextPermutation(int* A, int n1) {
    int i,temp,n=0;
    for(i=0;i<n1-1;i++){
        if(A[i]<A[i+1]){
            n=1;
			break;
        }
    }
    if(n1==1)
    n=1;
    if(n==1){
        for(i=n1-1;i>=0;i--)
        printf("%d ",A[i]);
    }
    else{
        for(i=n1-1;i>0;i--){
            if(A[i]>A[i-1]){
            	printf("Here--%d\n",A[i]);
                temp=A[i-1];
                A[i-1]=A[i];
                A[i]=temp;
                quicksort(A,i,n1-1);
                break;
            }
        }
        for(i=0;i<n1;i++)
        printf("%d ",A[i]);
    }
}
int main(){
	int a[]={3,1,5};
	nextPermutation(a,3);
}
