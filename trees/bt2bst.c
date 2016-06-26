#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct tree{
	int val;
	struct tree *left,*right;
};
int arr[100];
int arr_count=0;

struct node* createnode(int val){
	struct tree* temp;
	temp=(struct node*)malloc(sizeof(struct tree));
	temp->val=val;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void inorder(struct tree *root,int n){
	if(!root)
	return;
	else{
		inorder(root->left,n);
		
		if(n==0)
		printf("%d ",root->val);
		else if(n==1)
		arr[arr_count++]=root->val;
		else if(n==2)
		root->val=arr[arr_count++];
		
		inorder(root->right,n);
	}
}
void quick_sort(int start,int end){
	
	if(start<end){
		int pivot=start;
		int i,j,temp;
		i=start;j=end;
		while(arr[i]<=arr[pivot] && i<end)
		i++;
		while(arr[j]>arr[pivot] && j>=0)
		j--;
		if(i<j){
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}		
	
		temp=arr[j];
		arr[j]=arr[pivot];
		arr[pivot]=temp;
	
		quick_sort(start,j-1);
		quick_sort(j+1,end);
	}
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
	
	printf("BT: ");
	inorder(root,0);
	
	printf("\nArray  Count: %d\n",arr_count);
	
	inorder(root,1);
	printf("Array  Count: %d\n",arr_count);
	
	quick_sort(0,arr_count-1);

	arr_count=0;
	
	inorder(root,2);
	printf("Array  Count: %d\n",arr_count);
	
	printf("BST: ");
	inorder(root,0);
	return 0;
}
