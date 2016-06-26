#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node *r;
};
struct node* createnode(int val){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->val=val;
	temp->r=NULL;
	return temp;
}

int main(){
	int t,n,i,j,len;
	scanf("%d",&t);
	while(t--){
		struct node *stk = NULL;
		int size=0,flag=0;
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		
		for(i=0;i<n;i++){
			flag=0;
			if(stk==NULL){
				struct node *temp=createnode(a[i]);
				size++;
				stk=temp;
			}
			else{
				struct node *temp=stk;
				while(temp){
					if(temp->val>a[i]){
						//printf("Updated from %d to %d\n",temp->val,a[i]);
						temp->val=a[i];
						flag=1;
						break;
					}
					temp=temp->r;
				}
				if(flag==0){
					temp=createnode(a[i]);
					struct node *ptr=stk;
					while(ptr->r){
						ptr=ptr->r;
					}
					ptr->r=temp;
					size++;
					//temp->l=ptr;
				}
			}
		}
		struct node *temp=stk;
		printf("%d ",size);
		while(temp){
			printf("%d ",temp->val);
			temp=temp->r;
		}
		printf("\n");
	}
}
