#include<stdio.h>
#include<math.h>

int main(){
	long long int i,curr,t,l,r,count;
	scanf("%lld",&t);
	while(t--){
		count=0;
		scanf("%lld%lld",&l,&r);
		for(i=1;i<61;i++){
			curr=pow(2,i);
			if(curr>=l && curr<=r){
				count++;
			}
			curr=curr*3;
			while(curr<=r){
				if(curr>=l){
					count++;
				}
				curr=curr*3;
			}
		}
		if(l==1){
			count++;
		}
		printf("%lld\n",count);
	}
}
