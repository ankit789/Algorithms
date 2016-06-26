#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct tree{
	int val;
	struct tree *left,*right;
};
int lcount,rcount;
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
void sum_vertical(struct tree *root,int *sum,int col,int lmax){
	if(!root) return;
	sum[lmax+col]+=root->val;
	sum_vertical(root->left,sum,col-1,lmax);
	sum_vertical(root->right,sum,col+1,lmax);
}
void extreme(struct tree *root,int l,int r){
	
	if(!root)
	return;
	else{
		if(r>rcount)
		rcount=r;
		if(l<lcount)
		lcount=l;
		
		extreme(root->left,l-1,r);
		extreme(root->right,l,r+1);
	}
}
int main(){
	struct tree *root;
	root=createnode(50);
	int i=0;
	root->left=createnode(30);
	root->left->right=createnode(20);
	root->left->left=createnode(5);
	
	root->right=createnode(60);
	root->right->right=createnode(70);
	root->right->right->right=createnode(80);
	root->right->right->left=createnode(65);
	root->right->left=createnode(45);
	
	printf("Inorder: ");
	inorder(root);
	
	lcount=0;
	rcount=0;
	extreme(root,lcount,rcount);		
	
	//printf("\nL: %d R: %d",lcount,rcount);
	lcount*=-1;
	int n=lcount+rcount+1;
	int col=0;
	
	int *sum=(int *)calloc(n,sizeof(int));
		
	sum_vertical(root,sum,lcount,col);
	
	printf("\nVertical Sum: ");
	for(i=0;i<n;i++)
	printf("%d ",sum[i]);
	
	return 0;
}


