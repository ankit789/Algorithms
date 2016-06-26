#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define AS 26
struct trie_node{
	int value;
	struct trie_node *child[AS];
};
struct trie{
	struct trie_node *root;
	int count;
};
struct trie_node* createnode(){
	struct trie_node *temp =NULL;
	temp = (struct trie_node*)malloc(sizeof(struct trie_node));
	temp->value=0;
	int i;
	for(i=0;i<AS;i++){
		temp->child[i]=NULL;
	}
	return temp;
}
int leafnode(struct trie_node *t){
	return (t->value!=0);
}
int freenode(struct trie_node *t){
	int i;
	for(i=0;i<AS;i++){
		if(t->child[i])
		return 0;
	}
	return 1;
}
void initialize(struct trie *t){
	t->root = createnode();
	t->count++;
}
void insert(struct trie *t,char s[]){
	int l = strlen(s);
	t->count++;
	struct trie_node *temp;
	temp = t->root;
	int i,ind;
	for(i=0;i<l;i++){
		ind = s[i]-'a';
		if(temp->child[ind]==NULL){
			temp->child[ind]=createnode();
		}
		temp= temp->child[ind];
	}
	temp->value=t->count;
}
int search(struct trie *t,char s[]){
	int i,ind,l,flag=1;
	l=strlen(s);
	struct trie_node *temp;
	temp = t->root;
	
	for(i=0;i<l;i++){
		ind = s[i]-'a';
		if(temp->child[ind]==NULL){
			flag=0;
			break;
		}
		temp=temp->child[ind];
		//printf("Traversed child: '%c'\n",ind+'a');
	}
	if(flag && temp->value==0){
		flag=0;
	}
	return flag;
}
int deletekey(struct trie_node *t,char s[],int i,int len){
	if(!t)
	return 0;
	
	if(i==len){
		if(t->value){
			t->value=0;
			printf("Deleted!\n");
			if(freenode(t))
			return 1;
			return 0;
		}
	}
	else{
		int ind = s[i]-'a';
		if(deletekey(t->child[ind],s,i+1,len)){
			free(t->child[ind]);
			t->child[ind]=NULL;
			
			return (!leafnode(t) && freenode(t));
		}
	}
	return 0;
}
void del(struct trie *t,char s[]){
	int l = strlen(s);
	if(l>0){
		deletekey(t->root,s,0,l);
		//if(deletekey(t->root,s,0,l))
		//printf("Deleted!\n");
		//else printf("Couldn't Delete or Not Present!\n");
	}
}
int main(){
	char s[1000];
	int i=0,j,k,m,n;
	struct trie t;
	char ch='y';
	initialize(&t);
	do{
		j=0;
		printf("Enter: 1.) Insert 2.) Search 3.) Delete\n");
		scanf("%d",&j);
		switch(j){
			case 1:
				printf("Enter String to Insert: ");
				scanf("%s",&s);
				insert(&t,s);
				break;
			case 2:
				printf("Enter String to Search: ");
				scanf("%s",&s);
				if(search(&t,s))
				printf("Yes! Present\n");
				else printf("No! not Present\n");
				break;
			case 3:
				printf("Enter String to Delete: ");
				scanf("%s",s);
				del(&t,s);
				break;
				
			default:
				printf("Wrong Input!\n");
		}
		printf("Press n/N to break: ");
		fflush(stdin);
		scanf("%c",&ch);
		
	}while(ch!='n' && ch!='N');
	
	return 0;
}
