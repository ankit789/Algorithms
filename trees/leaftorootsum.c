#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct tree{
	int val;
	struct tree *left,*right;
};


struct node* createnode(int val){
	struct tree* temp;
	temp=(struct node*)malloc(sizeof(struct tree));
	temp->val=val;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

struct tree* create_tree(struct tree *temp,int i){

	if(!temp){
		temp=createnode(i);
	}
	else if(temp->val>i){
		temp->left=create_tree(temp->left,i);
	}
	else{
		temp->right=create_tree(temp->right,i);
	}
	return temp;
}
void inorder(struct tree *root){
	if(!root)
	return;
	else{
		inorder(root->left);
		printf("%d ",root->val);
		inorder(root->right);
	}
}

int main(){
	struct tree *head=NULL;
	int i,k;
	char ch='y';
	do{
		printf("Enter Val: ");
		scanf("%d",&i);
		head=create_tree(head,i);					
		printf("Enter y/Y to continue: ");
		scanf(" %c",&ch);
		
	}while(ch=='y'||ch=='Y');
	
	printf("\nInorder: ");
	inorder(head);	
	printf("\n");
	
	
}
