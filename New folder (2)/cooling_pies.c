#include<stdio.h>
#include<stdlib.h>
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
int main(){
		
	int i,j,t,n,*a,*b,count;
	scanf("%d",&t);
	while(t--){
	count=0;
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	b=(int*)malloc(n*sizeof(int));
	
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	for(i=0;i<n;i++)
	scanf("%d",&b[i]);
	
	quicksort(a,0,n-1);
	quicksort(b,0,n-1);
	
	
	i=0;j=0;
	while(i<n && j<n){
		if(a[i]<=b[j]){
			i++;
			j++;
			count++;
		}
		else
		j++;
	}
	//printf("%c\n",s[i-1]);
	printf("%d\n",count);
	
	}
	
	return 0;
}
