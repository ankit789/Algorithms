#include<bits/stdc++.h>

#define MAX 26
using namespace std;
struct trie_node{
	int value;
	struct trie_node *child[MAX];
};
struct trie{
	struct trie_node *root;
	int count;
};

struct trie_node* newnode(){
	struct trie_node *temp = (struct trie_node*)malloc(sizeof(struct trie_node));
	temp->value=0;
	for(int i=0;i<MAX;i++){
		temp->child[i]=NULL;
	}
	return temp;
} 

void initialize(struct trie *t){
	t->root = newnode();
	t->count=0;
}
int getIndex(char c){
	//cout<<"Query for "<<c<<endl;
	return (int)(c-'a');
}
void insert(struct trie *root,char key[]){
	struct trie_node *temp = root->root;
	root->count++;
	int len = strlen(key);
	int index;
	for(int i=0;i<len;i++){
		index = getIndex(key[i]);
		if(!(temp->child[index]))
		temp->child[index]=newnode();
		temp = temp->child[index];
	}
	temp->value = root->count;
}

int search(struct trie *root,char key[]){
	struct trie_node *temp = root->root;
	int len = strlen(key);
	int index;
	for(int i=0;i<len;i++){
		index = getIndex(key[i]);
		if(!(temp->child[index])){
			return 0;
		}
		temp = temp->child[index];
	}
	return 1;
}
void display(struct trie_node *temp,char *res,int index){
	if(!temp) return;
	
	if(temp->value!=0){
		res[index]='\0';
		cout<<"Found: "<<res<<endl;
	//	return;
	}
	
	for(int i=0;i<MAX;i++){
		if(temp->child[i]){
			//cout<<"Inserting "<<(char)('a'+i)<<endl;
			res[index]=(char)('a'+i);
			display(temp->child[i],res,index+1);
		}
	}
	
}
int main(){
	struct trie *root = (struct trie*)malloc(sizeof(struct trie));
	initialize(root);
	
	char dict[][10]={"hello","here","this","there","their","ok"};
	for(int i=0;i<6;i++){
		//cout<<"Inserting "<<dict[i]<<endl;
		insert(root,dict[i]);
	}
	
	/*
	if(search(root,"hello1")){
		cout<<"Key Present!"<<endl;
	}else{
		cout<<"Key not present!"<<endl;
	}
	*/
	char res[10];
	int index=0;
	display(root->root,res,index);
	
	
	return 0;
}
