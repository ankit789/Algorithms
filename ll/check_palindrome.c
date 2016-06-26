#include<stdio.h>
#include<stdlib.h>
struct node{
	char data;
	struct node* next;
};
struct node* createnode(char val){
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=val;
	temp->next=NULL;
	return temp;
}
create_ll(struct node **head){
	struct node *temp;
	char ch='y',i;
	do{
		printf("Enter Char: ");
		scanf(" %c",&i);
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
		printf("%c",head->data);
		head=head->next;
	}
	printf("\n");
}
void reverse(struct node **head){
	struct node *curr,*prev,*next;
	prev=NULL;
	curr=next=*head;
	while(curr){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	*head=prev;
}
int compare(struct node *head1,struct node *head2){
	while(head1 && head2){
		if(head1->data!=head2->data)
		return 0;
		head1=head1->next;
		head2=head2->next;
	}
	if(head1 || head2)
	return 0;
	else return 1;
}
void check_palindrome(struct node *head){
	struct node *temp1,*temp2,*prev,*mid;
	temp1=temp2=head;
	while(temp2!=NULL && temp2->next!=NULL){
		temp2=temp2->next->next;
		prev=temp1;
		temp1=temp1->next;
	}
	if(temp2!=NULL){
		mid=temp1;
		temp1=temp1->next;	
	}
	prev->next=NULL;
	//second=temp1;
	reverse(&temp1);
	int x=compare(head,temp1);
	reverse(&temp1);
	if(temp2!=NULL){
		prev->next=mid;
		mid->next=temp1;
	}
	else
	prev->next=temp1;
	
	if(x==1)
	printf("Yes, It is a Palindrome!\n");
	else
	printf("No!\n");
	
	return;
}

int main(){
	struct node *head=NULL;
	create_ll(&head);
	
	print(head);
	
	check_palindrome(head);
	
}

