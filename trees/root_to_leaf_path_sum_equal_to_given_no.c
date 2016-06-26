#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
	int data;
	struct tree *left,*right;
}tree;

struct tree* createnode(int val){
	tree* tmp = malloc(sizeof(tree));
	tmp->data=val;
	tmp->left=tmp->right=NULL;
	return tmp;
}

void _inorder(tree* root){
	if(!root) return;
	_inorder(root->left);
	printf("%d",root->data);
	_inorder(root->right);
}
void inorder(tree* root){
	printf("Inorder Traversal: ");
	_inorder(root);
}

void printArr(int *a,int n){
	printf("Array: ");
	int i;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
void root2leafpath(tree *root,int sum,int *sumArr,int index){
	if(!root) return;
	if(!root->left && !root->right && sum==root->data){
		sumArr[index++]=root->data;
		printArr(sumArr,index);
		return;
	}
	sum-=root->data;
	sumArr[index++]=root->data;
	root2leafpath(root->left,sum,sumArr,index);
	root2leafpath(root->right,sum,sumArr,index);
}

void allroot2leafpath(tree *root,int *sumArr,int index){
	if(!root) return;
	if(!root->left && !root->right){
		sumArr[index++]=root->data;
		printArr(sumArr,index);
		return;
	}
	sumArr[index++]=root->data;
	allroot2leafpath(root->left,sumArr,index);
	allroot2leafpath(root->right,sumArr,index);
}

int main(){
	tree *root;
	root = createnode(10);
	root->left = createnode(8);
	root->right = createnode(9);
	root->left->left = createnode(3);
	root->left->right = createnode(5);
	root->right->left = createnode(2);
	
	int sum;
	int sumArr[100];
	int index=0;
	
	printf("ALL ROOT TO LEAF PATHS:-\n");
	allroot2leafpath(root,sumArr,index);
	
	printf("Enter Sum: ");
	scanf("%d",&sum);
	root2leafpath(root,sum,sumArr,index);
	
	return 0;
}
