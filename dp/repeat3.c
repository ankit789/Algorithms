#include<stdio.h>

int check(int *A,int x,int t,int n1){
    int i,k=0;
    for(i=0;i<n1;i++){
        if(A[i]==x)
        k++;
    }
    if(k>t)
    return x;
    else return 0;
    
}
int repeatedNumber(const int* A, int n1) {
    
    int i,j,t=n1/3,a,b,c,x=0,y=0,z=0;
    
    for(i=0;i<n1;i++){
        if(x>0&&y>0&&z>0){
            x--;y--;z--;
        }
        if((A[i]==a && x)|| (A[i]==b && y) || (A[i]==a && z)){
        		if(A[i]==a&&x){
        			x++;
        		}
        		else if(A[i]==b&&y){
        			y++;
        		}
        		else if(A[i]==c&&z)
        		z++;
        }
        else if(x==0){
        	//printf("in x\n");
            a=A[i];
            x++;
        }
        
        else if(y==0){
        	b=A[i];
            y++;
        }
        
        else if(z==0){
        	c=A[i];
            z++;
        }
        
    }
    printf("%d %d %d\n",x,y,z);
    if(x){
    	printf("x: %d\n",a);
        j=check(A,a,t,n1);
        if(j)
        return j;
    }
    if(y){
    	printf("y: %d\n",b);
        j=check(A,b,t,n1);
        if(j)
        return j;
    }
    if(z){
    	printf("z: %d\n",c);
        j=check(A,c,t,n1);
        if(j)
        return j;
    }
    return -1;
    
}
int main(){
	const int a[]={1};
	int n=sizeof(a)/sizeof(int);
	printf("n: %d Ans: %d",n,repeatedNumber(a,n));
}
