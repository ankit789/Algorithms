#include<stdio.h>
#include<stdlib.h>
void plusOne(int* A, int n1, int *length_of_array) {
	// SAMPLE CODE
        /*
         * *length_of_array = n1 + 1; // length of result array
         * int *result = (int *) malloc(*length_of_array * sizeof(int));
         * // DO STUFF HERE. NOTE : length_of_array can be n1 OR n1 + 1. 
         * return result;
         */
         int i,j=n1,c=1,*result;
         for(i=n1-1;i>=0;i--){
             A[i]=A[i]+c;
             c=A[i]/10;
             A[i]=A[i]%10;
         }
         if(c){
             *length_of_array = n1+1;
             result = (int*)malloc(*length_of_array * sizeof(int));
             result[0]=c;
             for(i=0;i<n1;i++)
             result[i+1]=A[i];
         }
         else{
             //printf("Carry Is Zero!");
             for(i=0;i<n1;i++){
                 if(A[i]) break;
                 else j--;
             }
             if(j!=n1){
                *length_of_array = j;
                result = (int*)malloc(*length_of_array * sizeof(int)); 
                for(i=0;i<j;i++)
                result[i]=A[i+n1-j];
             }
             else{
                *length_of_array = n1;
                result = (int*)malloc(*length_of_array * sizeof(int)); 
                for(i=0;i<n1;i++)
                result[i]=A[i];
             }
         }
         n1=j;
         for(i=0;i<n1;i++)
         printf("%d ",result[i]);
}
int main(){
	int a[]={0,3,7,6,4,0,5,5,5},n;
	plusOne(a,9,&n);
}


x=(actsum-reqsum);
y=actsq-reqsq;
z=y/x;

result[0]=(z+x)/2;
result[1]=z-result[0];
