#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node* createnode(int val){
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=val;
	temp->next=NULL;
	return temp;
}

create_ll(struct node **head){
	struct node *temp;
	char ch='y';
	int i;
	do{
		printf("Enter Value: ");
		scanf("%d",&i);
		if(*head==NULL){
			*head=createnode(i);
			temp=*head;
			//printf("%c ",head->data);
		}
		else{
			temp->next=createnode(i);
			temp=temp->next;
		}
		
		printf("Press Y/y to continue: ");
		scanf(" %c",&ch);
		
	}while(ch=='y'||ch=='Y');
}
void print(struct node *head){
	printf("Entered LL: ");
	while(head){
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}


int main(){
	int i,j;
	struct node *head=NULL;
	create_ll(&head);
	
	print(head);
	
	struct node *curr,*prev,*end,*temp,*temp2;
	curr=end=temp=head;
	
	while(end->next){
		end=end->next;
	}
	
	struct node *end2=end;
	while((temp->data)%2==1){
		end2->next=temp;
		temp2=temp->next;
		temp->next=NULL;
		end2=temp;
		temp=temp2;
	}
	head=temp;
	curr=temp;
	while(curr!=end){
		if((curr->data)%2==1){
			prev->next=curr->next;
			end2->next=curr;
			curr->next=NULL;
			end2=curr;
			curr=prev->next;
		}
		else{
			prev=curr;
			curr=curr->next;
		}
	}
	
	print(head);
	return 0;
}

