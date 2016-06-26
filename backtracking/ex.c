
#include<stdio.h>
#include<stdlib.h>
#define SWAP(x,y) typeof(x) temp=x;x=y;y=temp;

void print(int *a,int n){
	int i;
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	printf("\n");
}
int get(int a,int b){
    int count_a=0,count_b=0;
    int i;
    int p=a,q=b;
    while(p>0){
        count_a++;
        p=p/10;
    }
    while(q>0){
        count_b++;
        q=q/10;
    }
    char x[p+q+1],y[p+q+1];
    
    x[p+q]=y[p+q]='\0';
    
    p=a;q=b;
    i=count_a+count_b-1;
    while(p>0 && i>=0){
        x[i]=p%10+'0';
        p=p/10;
        i--;
    }
    while(q>0 && i>=0){
        x[i]=q%10+'0';
        q=q/10;
        i--;
    }
    
    p=a;q=b;
    i=count_a+count_b-1;
    while(q>0 && i>=0){
        y[i]=q%10+'0';
        q=q/10;
        i--;
    }
    while(p>0 && i>=0){
        y[i]=p%10+'0';
        p=p/10;
        i--;
    }
    // -----  x == a+b ;; y == b+a ----
    //printf("\n%s -- %s\n",x,y);
    
    int res=strcmp(y,x);
    //printf("Compare Results of %d %d %d\n",a,b,res);
    if(res>0)
    return 1;
    else return 0;
}
void sort(int *a,int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[i]!=a[j]){
                if(get(a[j],a[i])){
                	//printf("Swapped: %d %d\n",a[j],a[i]);
                	//int temp=a[j]; a[j]=a[i]; a[i]=temp;
                	SWAP(a[j],a[i]);
                }
            }
        }
    }
}
void add(char *s,int a,int *size){
    int i=0,j,count=0;
    while(i!=*size)
    i++;
    int p=a;
    while(p>0){
        count++;
        p=p/10;
    }
    //char b[count];
    //printf("%d\n",count);
    p=a;
    for(j=count-1;j>=0 && p>0;j--){
        s[i+j]=p%10+'0';
        //printf("%c",s[i+j]);
        p=p/10;
    }
    *size=*size+count;
}
char* largestNumber(const int* A, int n1) {
    int i,a[n1];
    for(i=0;i<n1;i++){
        a[i]=A[i];
    }
   // print(a,n1);
    sort(a,n1);
    
    char s[100];
    int size=0;
    
	//print(a,n1);
	
    for(i=0;i<n1;i++){
        add(s,a[i],&size);
        //printf("%s ",s);
    }
    s[size]='\0';
    return s;
}

void main(){
	const int a[]={1,45},n=2;
	
	//print(a,n);
	printf("Req String: %s",largestNumber(a,n));
	
}

