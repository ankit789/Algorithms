#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct tree{
	int val,height;
	struct tree *left,*right;
};

struct tree* createnode(int val){
	struct tree *temp;
	temp=(struct tree*)malloc(sizeof(struct tree));
	temp->val=val;
	temp->left=NULL;
	temp->right=NULL;
	temp->height=1;
	return temp;
}
int max(int a,int b){
	return a>b?a:b;
}
int height(struct tree *temp){
	if(!temp) return 0;
	else
	return temp->height;
}
int bfactor(struct tree *temp){
	if(!temp) return 0;
	return height(temp->left)-height(temp->right);
}
struct tree* rightrotate(struct tree *temp){
	struct tree *x;
	x=temp->left;
	//y=x->left;
	temp->left = x->right;
	x->right=temp;
	
	x->height = max(height(x->left),height(x->right))+1;
	temp->height = max(height(temp->left),height(temp->right))+1;
	
	return x;
}
struct tree* leftrotate(struct tree *temp){
	struct tree *x;
	x=temp->right;
	//y=x->left;
	temp->right = x->left;
	x->left=temp;
	
	x->height = max(height(x->left),height(x->right))+1;
	temp->height = max(height(temp->left),height(temp->right))+1;
	
	return x;
}
struct tree* create_tree(struct tree *temp,int i){

	if(!temp){
		return createnode(i);
	}
	else if(temp->val>i){
		temp->left=create_tree(temp->left,i);
	}
	else{
		temp->right=create_tree(temp->right,i);
	}
	
	temp->height = max(height(temp->left),height(temp->right))+1;
	
	int balance = bfactor(temp);
	
	if(balance>1 && i < temp->left->val){
		return rightrotate(temp);
	}
	else if(balance<-1 && i > temp->right->val){
		return leftrotate(temp);
	}
	else if(balance>1 && i > temp->left->val){
		temp->left=leftrotate(temp->left);
		return rightrotate(temp);
	}
	else if(balance<-1 && i < temp->right->val){
		temp->right=rightrotate(temp->right);
		return leftrotate(temp);
	}

	return temp;
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
struct tree* findmin(struct tree *temp){
	while(temp->left){
		temp=temp->left;
	}
	return temp;
}
struct tree* del(struct tree *root,int key){
	if(!root)
	return root;
	
	if(root->val > key){
		root->left = del(root->left,key);
	}
	else if(root->val < key){
		root->right = del(root->right,key);
	}
	else{
		struct tree *temp;
		if(!root->left && !root->right){
			temp = root;
			root=NULL;
			free(temp);
		}
		else if(!root->left || !root->right){
			temp=root->left?root->left:root->right;
			*root = *temp;
			free(temp);
		}
		else{
			temp = findmin(root->right);
			root->val = temp->val;
			root->right = del(root->right,temp->val);
		}
	}
	
	if(!root)
	return root;
	
	root->height = max(height(root->left),height(root->right))+1;
	
	int balance = bfactor(root);
	
	if(balance>1 && key < root->left->val){
		return rightrotate(root);
	}
	else if(balance<-1 && key > root->right->val){
		return leftrotate(root);
	}
	else if(balance>1 && key > root->left->val){
		root->left=leftrotate(root->left);
		return rightrotate(root);
	}
	else if(balance<-1 && key < root->right->val){
		root->right=rightrotate(root->right);
		return leftrotate(root);
	}

	return root;
	
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
	
	printf("\nPreorder: ");
	preorder(head);	
	printf("\n");
	
	ch='y';
	do{
		printf("Enter node val to delete: ");
		scanf("%d",&i);
		head=del(head,i);
		printf("Enter y/Y to continue: ");
		scanf(" %c",&ch);
	}while(ch=='y'||ch=='Y');
	
	printf("\nPreorder: ");
	preorder(head);	
	printf("\n");
}
