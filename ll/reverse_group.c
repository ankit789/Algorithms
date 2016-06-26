#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node *next;
};

struct node* createnode(int val){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->val=val;
	temp->next=NULL;
	return temp;
}
void printll(struct node *node){
	printf("LL: ");
	while(node!=NULL){
		printf("%d ", node->val);
		node = node->next;
	}
	printf("\n");
}
struct node* reverse(struct node *head,int k){
	struct node *curr,*next,*prev=NULL,*temp;
	int count=0;
	curr = head;
	while(curr && count<k){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}
	
	if(next){
		head->next = reverse(next,k);
	}
	return prev;
}
int main(){
	struct node *head=NULL,*temp;
	int i,j,n;
	char c='y';
	do{
		
		scanf("%d",&i);
		while(i--){
			scanf("%d",&n);
			if(!head){
				head=createnode(n);
				temp=head;
			}
			else{
				while(temp->next){
					temp=temp->next;
				}
				temp->next=createnode(n);
			}
		}
	}while(0);
	
	printll(head);
	int k;
	scanf("%d",&k);
	head = reverse(head,k);
	printf("Reversed: ");
	printll(head);
	return 0;
}
