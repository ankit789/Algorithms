#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
void findPalind(char *arr)
{
    int flag=0,i,j,l,count[256]={0};
    l=strlen(arr);
	for(i=0;i<l;i++){
		count[arr[i]]++;
	}
	if(l%2==0){
		for(i=0;i<256;i++){
			if(count[i]%2!=0){
				flag=1;
			//	printf("Break at: %c\n",i);
				break;
			}
		}
    }else{
    	int c=1;
    	for(i=0;i<256;i++){
    		if(count[i]%2==1 && c>0){
    			c--;
    		}
    		else if(count[i]%2!=0){
    			flag=1;
    			//printf("Break at: %c\n",i);
    			break;
    		}
    	}
    }
    
    if (flag==0)
        printf("YES\n");
    else
        printf("NO\n");
    
}
int main() {

    char arr[100001];
    scanf("%s",arr);
    findPalind(arr);
    return 0;
}

