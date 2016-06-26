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
  while(node!=NULL)
  {
   printf("%d ", node->val);
   node = node->next;
  }
  printf("\n");
}
struct node* merge(struct node *a,struct node *b){
	if(a==NULL) return b;
	else if(b==NULL) return a;
	else{
		struct node *res;
		if(a->val < b->val){
			res=a;
			res->next=merge(a->next,b);
		}else{
			res = b;
			res->next = merge(a,b->next);
		}
		return res;
	}
}

void split(struct node *head,struct node **a,struct node **b){
	if(head==NULL || head->next==NULL){
		*a = head;
		*b = NULL;
	}
	else{
		struct node *slow,*fast;
		slow=head;
		fast=head->next;
		while(fast){
			fast=fast->next;
			if(fast){
				fast=fast->next;
				slow=slow->next;
			}
		}
		*a = head;
		*b = slow->next;
		slow->next = NULL;
	}
}
void mergesort(struct node **head){
	struct node *a,*b;
	if(*head==NULL||(*head)->next == NULL){
		return;
	}
	split(*head,&a,&b);
	mergesort(&a);
	mergesort(&b);
	*head = merge(a,b);
}
int main(){
	struct node *head=NULL,*temp;
	int i,j,n;
	char c='y';
	do{
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
		printf("Press y to continue: ");
		fflush(stdin);
		scanf("%c",&c);
		
	}while(c=='y'|| c=='Y');
	
	printll(head);
	mergesort(&head);
	printf("Sorted ");
	printll(head);
	return 0;
}
