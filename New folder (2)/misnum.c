#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long
#define N 1000000000
ll int a[31623],c[100000000];
int main(){
	ll int i,r,t,j,n,k,l,p,x,count=0;
	r=31622;
	FILE *fp;
	fp=fopen("prime2.txt","w");
	fprintf(fp,"%s","{ ");
	for(i=1;i<=r;i++){
		a[i]=1;
	}
	a[1]=0;
	for(i=2;i<=r;i++){
		if(a[i]==1){
			x=i*2;
			k=2;
			while(x<=r){
				a[x]=0;
				k++;
				x=i*k;
			}
		}
	}
	
	for(i=2;i<=r;i++){
		if(a[i]==1){
			c[count++]=i;
			fprintf(fp,"%lld",i);
			fprintf(fp,"%s",", ");
			
		}
	}
	//printf("No. of Primes Here: %lld\n",count);
	p=count-1;
	int flag=0;
	for(i=r+1;i<=N;i++){
		flag=0;
		for(j=0;j<=p;j++){
			if(i%c[j]==0){
				flag=1;
				break;	
			}
			if(flag)
			break;
		}
		if(flag==0){
		
		//printf("%lld\n",count);
		c[count++]=i;
		fprintf(fp,"%lld",i);
		fprintf(fp,"%s",", ");
		}
	}
	//printf("No. of Prime: %lld\n",count);
	
	
	
	fprintf(fp,"%s","};");
	fclose(fp);
	//printf("%lld",j);
	//scanf("%lld",&t);
	//memset(a,1,sizeof(a));
	
	return 0;
}
