#include <iostream>
#include <string.h>
#include <stdio.h>
#include<stdlib.h>
using namespace std;
 
// Binary search
int GetCeilIndex(int A[], int T[], int l, int r, int key) {
   int m;
 
   while( r - l > 1 ) {
      m = l + (r - l)/2;
      if( A[T[m]] >= key )
         r = m;
      else
         l = m;
   }
 
   return r;
}
 
int lis(int A[], int size) {
   // Add boundary case, when array size is zero
   // Depend on smart pointers
 
   int *tailIndices = (int*)malloc(size*sizeof(int));
   int *prevIndices = (int*)malloc(size*sizeof(int));
   int len;
 
   memset(tailIndices, 0, sizeof(tailIndices));
   memset(prevIndices, 0xFF, sizeof(prevIndices));
 
   tailIndices[0] = 0;
   prevIndices[0] = -1;
   len = 1; // it will always point to empty location
   for( int i = 1; i < size; i++ ) {
      if( A[i] < A[tailIndices[0]] ) {
         // new smallest value
         tailIndices[0] = i;
      } else if( A[i] > A[tailIndices[len-1]] ) {
         // A[i] wants to extend largest subsequence
         prevIndices[i] = tailIndices[len-1];
         tailIndices[len++] = i;
      } else {
         // A[i] wants to be a potential condidate of future subsequence
         // It will replace ceil value in tailIndices
        int pos = GetCeilIndex(A, tailIndices, -1, len-1, A[i]);
 
        prevIndices[i] = tailIndices[pos-1];
        tailIndices[pos] = i;
      }
   }
   
   cout << "LIS of given input" << endl;
   for( int i = tailIndices[len-1]; i >= 0; i = prevIndices[i] )
      cout << A[i] << "   ";
   cout << endl;
 
   free(tailIndices);
   free(prevIndices);
 
   return len;
}
 
int main() {
   int A[] = { 3,4,5,1,1,2 };
   int size = sizeof(A)/sizeof(A[0]);
 
   printf("LIS size %d\n", lis(A, size));
 
   return 0;
}
