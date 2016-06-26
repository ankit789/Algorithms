#include<stdio.h>
#include<math.h>
#define ABS(a) a>0?a:(-1)*a;
void print(int i,int j){
	if(i>9) printf("%d",i);
	else printf("0%d",i);
	printf(":");
	if(j>9) printf("%d\n",j);
	else printf("0%d\n",j);
}
void printmat(double clock[12][60]){
	int i,j;
	printf("Matrix: \n");
	for(i=0;i<12;i++){
		for(j=0;i<60;j++){
			printf("%6.4lf",clock[i][j]);
		}
		printf("\n");
	}
}
int main(){
	double clock[12][60];
	int i,j,n,t;
	for(i=0;i<12;i++){
		for(j=0;j<60;j++){
			double min1 = (double)j;
			double hr1 = (double)i;
			//printf("min: %0.4lf hr: %0.4lf\n",min1,hr1);
			double min_diff = (min1*6)/1.0;
			double hr_diff = ((hr1*30)+(min1*30)/(60.0))/1.0;
			
			double angle = ABS((min_diff-hr_diff));
			
			clock[i][j]=(double)(angle>180)?360-angle:angle;
			
		}
	}
	//printmat(clock);
	scanf("%d",&t);
	double p =1/120.0;
	//printf("%lf\n",p);
	while(t--){
		int flag=0;
		double a;
		int min,hr;
		scanf("%lf",&a);
		
		
		//printf("%lf ",a);
		for(i=0;i<12;i++){
			for(j=0;j<60;j++){
				double x = clock[i][j]-a;
				x=x>=0?x:x*-1;
				if(x<p){
					//min=j;hr=i;
				//	printf("%d %d -- ",i,j);
					//printf("%lf\n",x);
					print(i,j);
					//printf("\n");
				}
			}	
		}		
	}
}
