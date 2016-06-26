#include<stdio.h>
#include<stdlib.h>
struct node{
	int val;
	struct node *left,*right,*nextryt;
};
int max(int a,int b){
	return a>b?a:b;
}
void inorder(struct node *root){
	if(!root)
	return;
	else{
		inorder(root->left);
		printf("%d ",root->val);
		inorder(root->right);
	}
}
struct node* createnode(int val){
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->val=val;
	temp->left=NULL;
	temp->right=NULL;
	temp->nextryt=NULL;
	return temp;
}
int height(struct node *root){
	if(!root)
	return 0;
	
	int lh = height(root->left);
	int rh = height(root->right);
	return max(lh,rh)+1;
	
}
void connect(struct node *root,int level,struct node **prev,struct node **head){
	if(!root) return;
	if(level==1){
		if(*head==NULL){
			*head=root;
			printf("Head: %d\n",(*head)->val);
		}else{
			(*prev)->nextryt=root;
		}
		(*prev)=root;
	}
	if(level>1){
		connect(root->left,level-1,prev,head);
		connect(root->right,level-1,prev,head);
	}
}
int main(){
	struct node *root;
	root=createnode(1);
	
	root->left=createnode(2);
	root->right=createnode(3);
	
	root->left->left=createnode(4);
	root->left->right=createnode(5);
	root->right->left=createnode(6);
	root->right->right=createnode(7);
	
	root->left->left->left=createnode(8);
	root->left->left->right=createnode(9);
	root->right->right->left=createnode(10);
	root->right->right->right=createnode(11);
	
	
	
	printf("BT-Inorder: ");
	inorder(root);
	printf("\n");
	
	int h = height(root);
	int i;
	struct node *head[h+1];
	for(i=1;i<=h;i++){
		head[i]=NULL;
	}
	for(i=1;i<=h;i++){
		struct node *prev=NULL;
		connect(root,i,&prev,&head[i]);
	}
	
	printf("LL at tree: ");
	for(i=1;i<=h;i++){
		printf("Level %d: ",i);
		struct node *temp=head[i];
		while(temp){
			printf("%d ",temp->val);
			temp=temp->nextryt;
		}
		printf("\n");
	}
	return 0;
}
