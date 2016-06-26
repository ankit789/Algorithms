#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void maxset(int* A, int n1, int *length_of_array) {
    /*
     * Sample Code : 
     *  *length_of_array = 1;
     *  int * ret = (int *) malloc(sizeof(int) * *length_of_array);
     *  ret[0] = 1;
     *  return ret;
     */
     int max=A[0],sum=A[0],i,start,end,len=1,j=0;
     for(i=1;i<n1;i++){
         if(sum+A[i]>=A[i] && A[i]>=0){
             sum+=A[i];
             printf("%d -- %d\n",A[i],sum);
             len++;
         }
         else{
             if(max<=sum){
                 max=sum;
                 printf("%d\n",max);
                 end=i;
                 start=end-len;
             }
             len=1;
             sum=A[i];
         }
     }
     int* ret = (int*)malloc((end-start)*sizeof(int));
     for(i=start;i<end;i++){
        printf("%d ",A[i]);
        ret[j++]=A[i];
     }
     //return ret;
}
int main(){
	int l=4,p;
	int a[]={0,0,-1,0};
	maxset(a,l,&p);
}
