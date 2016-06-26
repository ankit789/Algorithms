#include<stdio.h>

int main(){
	int t,n,a[1001]={0},i;
	a[0]=0;
	for(i=10;i<=1000;i+=10){
		int j=i;
		if(j>100){
			j=j%100;
		}
		if((j>=10 && j<40) || (j>50 && j<80)){
			a[i]=a[i-10]+1;
		}else if(j==40 || j==80){
			a[i]=a[i-10]-1;
		}
		else if(j==50 || j==100){
			a[i]=1;
		}
		else if(j==0){
			j=a[i]/100;
			if((j<4 && j>0)||(j>5 && j<10)){
				a[i]=a[i-100]+1;
			}else if(j==4||j==8){
				a[i]=a[i-100]-1;
			}else if(j==5 || j==10){
				a[i]=1;
			}
		}
	}
	
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",a[n]);
	}
	return 0;
}
