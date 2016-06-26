#include<stdio.h>
#include<stdlib.h>
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
void inorder(struct tree *root){
	if(!root)
	return;
	else{
		inorder(root->left);
		printf("%d ",root->val);
		inorder(root->right);
	}
}
void preorder(struct tree *root){
	if(!root)
	return;
	else{
		printf("%d ",root->val);
		preorder(root->left);
		preorder(root->right);
	}
}
//-----------------Binary Tree to DLL Conversion----------------/////
void tree2dll(struct tree *root,struct tree **head){
	if(!root)
	return ;
	
	static struct tree *prev=NULL;
	
	tree2dll(root->left,head);
	if(!prev){
		*head=root;
	}
	else{
		prev->right=root;
		root->left=prev;
	}
	prev=root;
	
	tree2dll(root->right,head);
	
}
void print_dll(struct tree *root){
	printf("DLL: ");
	while(root->right){
		printf("%d --> ",root->val);
		root=root->right;
	}
	printf("%d \n",root->val);
	
}

//-----------------mrege sort on dll------------------------------

struct tree* getmid(struct tree *head){
	struct tree *slow,*fast,*temp;
	slow=fast=head;
	while(fast->right && fast->right->right){
		fast=fast->right->right;
		slow=slow->right;
	}
	temp=slow->right;
	slow->right=NULL;
	temp->left=NULL;
	return temp;
}

struct tree* merge(struct tree *head1,struct tree *head2){
	if(!head1) return head2;
	if(!head2) return head1;
	
	else if(head1->val<head2->val){
		head1->right=merge(head1->right,head2);
		head1->right->left=head1;
		head1->left=NULL;
		return head1;
	}
	else{
		head2->right=merge(head2->right,head1);
		head2->right->left=head2;
		head2->left=NULL;
		return head2;
	}
}
struct tree* merge_sort(struct tree *head){
	if(!head||!head->right)
	return head;
	else{
		struct tree *second=getmid(head);
		head=merge_sort(head);
		second=merge_sort(second);
		return merge(head,second);
	}
}
///--------------------------------dll to bst conversion-----------------
struct tree* dll2tree(struct tree **head,int n){
	if(n<=0)
	return NULL;
	
	struct tree *temp,*left;
	left = dll2tree(head,n/2);
	//temp->val=(*head)->val;
	temp = *head;
	*head = (*head)->right;
	temp->left=left;
	temp->right=dll2tree(head,n-n/2-1);
	
	return temp;
}

int main(){
	struct tree *root;
	root=createnode(50);
	root->left=createnode(30);
	root->left->right=createnode(20);
	root->left->left=createnode(5);
	root->right=createnode(60);
	root->right->right=createnode(70);
	root->right->right->right=createnode(80);
	root->right->right->left=createnode(65);
	root->right->left=createnode(45);
	
	printf("BT-Inorder: ");
	inorder(root);
	printf("\n");
	
	//--------------- Binary Tree to doubly linked list ------------
	struct tree *head=NULL;
	tree2dll(root,&head);
	
	print_dll(head);
	
	//---------------Merege sort on Dll -------------
	head=merge_sort(head);
	printf("Sorted ");
	print_dll(head);
	
	//----------------DLL to Binary Search Tree---------------
	int n=0;
	struct tree *temp=head;
	while(temp){
		temp=temp->right;
		n++;
	}
	
	root=dll2tree(&head,n);
	
	printf("BST-Inorder: ");
	inorder(root);
	printf("\n");
	
	printf("BST-Preorder: ");
	preorder(root);
	printf("\n");
	
	return 0;
	
}

