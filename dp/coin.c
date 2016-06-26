#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int n,m,*a,i,j;
	scanf("%d %d",&n,&m);
	a=(int*)malloc(m*sizeof(int));
	for(i=0;i<m;i++)
	scanf("%d",&a[i]);
	
	long int table[m+1][n+1];
	for(i=0;i<=n;i++){
		table[0][i]=0; 
	}
	for(i=0;i<=m;i++){
		table[i][0]=1;
	}
	
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(j-a[i-1]>=0)
			table[i][j]=table[i][j-a[i-1]]+table[i-1][j];
			else
			table[i][j]=table[i-1][j];
		}
		
	}
	printf("%ld",table[m][n]);
	
	return 0;
}
