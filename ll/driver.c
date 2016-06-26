#include<stdio.h>
#include<stdlib.h>

struct ll{
	int val;
	struct ll* next;
};

struct ll* createnode(int val){
	struct ll *temp = malloc(sizeof(struct ll));
	temp->val = val;
	temp->next = NULL;
	return temp;
}

void printll(struct ll *head){
	printf("Linked List: ");
	while(head){
		printf("%d ",head->val);
		head=head->next;
	}
	printf("\n");
}

int main(){
	struct ll *head;
	srand(time(NULL));
	
	head = createnode(rand()%100);
	head->next = createnode(rand()%100);
	head->next->next = createnode(rand()%100);
	head->next->next->next = createnode(rand()%100);
	head->next->next->next->next = createnode(rand()%100);
	head->next->next->next->next->next = createnode(rand()%100);
	
	printll(head);
	
	
	
	return 0;
}
