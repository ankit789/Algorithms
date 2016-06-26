#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
void add(char *final, char *b){
//	printf("a and b: %s %s\n",final,b);
	int i,j,la,lb,l,x,c,p;
	
	if(final[0]=='0'){
		strcpy(final,b);
	}
	else{
		
		la=strlen(final);
		lb=strlen(b);
		l=la>lb?la:lb;
		c=0;

		while(la!=0 && lb!=0){
			int t=(final[la-1]-'0')+(b[lb-1]-'0')+c;
			c=t/10;
			t=t%10;
			final[l-1]=t+'0';
			//printf("final[%d] : %c\n",l-1,final[l-1]);
			la--;lb--;l--;
		}
		
		if(lb!=0){
			while(lb){
				int t=b[lb-1]-'0'+c;
				c=t/10;
				t=t%10;
				final[l-1]=t+'0';
				//printf("final[%d] : %c\n",l-1,final[l-1]);
				l--;lb--;
			}
		}
		else if(la!=0){
		
			while(la){
					int t=final[la-1]-'0'+c;
					c=t/10;
					t=t%10;
					final[l-1]=t+'0';
					//printf("final[%d] : %c\n",l-1,final[l-1]);
					l--;la--;
				}
		}
		else{
			if(c){
			//	printf("Here---\n");
				p=strlen(final);
				//printf("%d\n",p);
				//printf("%c %c %c\n",final[0],final[1],final[2]);
				strrev(final);
				final[p]=c+'0';
				final[p+1]='\0';
				strrev(final);
			}
		}
		
	}
	printf("After adding to %s: result -- %s\n",b,final);	
}
char* sq(char *s){
	printf("Calculating sq. of: %s\n",s);
	int i,j,l,c1=0,c2=0,x,lt;
	char final[100000]={'0'};
	l=strlen(s);
//	printf("%d\n",l);
	for(i=l-1;i>=0;i--){
		c1=c2=lt=0;
		char temp[100000]={'0'};
	//	temp[lt++]='\0';
		for(j=0;j<l-i-1;j++){
			temp[lt++]='0';
		}
	//	printf("start temp -- %s\n",temp);
		for(j=l-1;j>=0;j--){
			int t=(s[j]-'0')*(s[i]-'0')+c1;
			c2=t/10;
			t=t%10;
			x=t%10;
			c1=c2;
			//printf("x is: %d\n",x);
			temp[lt++]=x+'0';
		}
		if(c2){
		//	printf("carry left: %d\n",c2);
			temp[lt++]=c2+'0';
		}
		//printf("len: %d\n",lt);
		//printf("before temp -- %s\n",temp);
		strrev(temp);
	//	printf("temp -- %s\n",temp);
		
		add(final,temp);
		
		//strcpy(final,add(final,temp));
		printf("final %s\n",final);
		//print(temp,"final");
	}
	return final;
}

int main(){
	char a[100000],b[100000],c[100000];
	int i,n;
	scanf("%s %s %d",&a,&b,&n);
	
	for(i=2;i<n;i++){
		strcpy(c,sq(b));
		add(c,a);
		strcpy(a,b);
		strcpy(b,c);
	}
	
	//sq(a);
	printf("%s",b);
	
	/*
	add(a,b);
	printf("%s\n",a);
	*/
	return 0;
}
