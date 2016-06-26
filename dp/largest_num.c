#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output string. Make sure the string ends with null character
 */
int getmsd(int a){
    int i=0,n;
    while(a>0){
        i=a%10;
        a=a/10;
    }
    return i;
}
int rem(int a){
	int i=0,n=a;
	while(n>0){
		i++;
		n=n/10;
	}
	return i;
}
int remmsd(int a){
	return a-(getmsd(a)*pow(10,rem(a)-1));
}
void printarr(int *a,int l){
	int i;
	printf("Array: ");
	for(i=0;i<l;i++)
	printf("%d ",a[i]);
}
char* largestNumber(const int* A, int n1) {
    char s[50];
    int *a;
    a=(int*)malloc(n1*sizeof(int));
    int sl=0,i,max=0,j,k,t,p;
    for(i=0;i<n1;i++)
    a[i]=A[i];
    for(j=0;j<n1;j++){
    	max=0;
        for(i=0;i<n1;i++){
            k=getmsd(a[i]);
            if(k>max){
                max=k;
                t=i;
                p=i;
            }
            else if(max==k){
                p=a[i]>a[t]?i:t;
            }
        }
        //printf("\n%d\n",a[p]);
        //printarr(a,n1);
        
		int x=rem(a[p]);
        while(x--){
        	s[sl++]=getmsd(a[p])+'0';
        	//printf("%c\n",s[sl-1]);
        	a[p]=remmsd(a[p]);
        }
        //printf("%c\n",s[sl-1]);
        a[p]=0;
    }
    s[sl]='\0';
    printf("%s",s);
    return s;
}
int main(){
	const int a[]={12345678,123456};
	largestNumber(a,2);
}
