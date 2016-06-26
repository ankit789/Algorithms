#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int val;
	struct node* next;
};
struct node* createnode(int i){
	struct node *temp =(struct node*)malloc(sizeof(struct node));
	temp->val = i;
	temp->next=NULL;
	return temp;
}
void pushl(struct node **temp,int i){
	struct node *t = createnode(i);
	(*temp)->next = t;
	(*temp) = t;
}
void pushf(struct node **temp,int i){
	struct node *t = createnode(i);
	t->next = *temp;
	*temp = t; 
}
int findnear(struct node *f,struct node *l,int i,int n){
	struct node *temp;
	temp = f;
	int j=0;
	while(temp->val > i){
		j++;
	}
	if(j<n/2) return 1;
	else return 0;
}
void printll(struct node *f){
	printf("LL: ");
	struct node *x = f;
	while(x){
		printf("%d ",x->val);
		x=x->next;
	}
	printf("\n");
}
int check(struct node *f,struct node *l){
	struct node *temp = f;
	struct node *p;
	int count =0;
	for(temp=f;temp!=NULL;temp=temp->next){
		for(p=temp->next;p!=NULL;p=p->next){
			if(p->val < temp->val){
				count++;
			}	
		}
	}
	return count;
}
int main(){
	int i,j,t,n,a[101],s,e;
	struct node *f,*l;
	
	scanf("%d",&t);
	while(t--){
		f=NULL;
		l=NULL;
		int ind,curr,ptr,no=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		f=createnode(a[0]);
		no=1;
		l=f;
		
		s=1;e=n-1;
		while(s<=e){
			curr = a[s]>a[e]?s:e;
			ptr = a[s]>a[e]?1:0;
			//printf("curr: %d ptr: %d\n",a[curr],ptr);
			if(a[curr] < f->val){
				pushf(&f,a[curr]);
				//printf("Front: ");
				//printll(f);
				no++;
				if(ptr){
					s++;
				}else{
					e--;
				}
				//printf("s: %d e: %d\n",s,e);
			}
			else if(a[curr] > l->val){
				pushl(&l,a[curr]);
				//printf("Last: ");
				//printll(f);
				no++;
				if(ptr){
					s++;
				}else{
					e--;
				}
				//printf("s: %d e: %d\n",s,e);
			}
			else{
				ind = findnear(f,l,a[curr],no);
				if(ind == 1){
					pushf(&f,a[curr]);
				//	printf("Front1: ");
				//	printll(f);
					no++;
					if(ptr){
					s++;
					}else{
						e--;
					}
				//	printf("s: %d e: %d\n",s,e);
				}else{
					pushl(&l,a[curr]);
				//	printf("Last1: ");
				//	printll(f);
					no++;
					if(ptr){
					s++;
					}else{
						e--;
					}
				//	printf("s: %d e: %d\n",s,e);
				}
			}
		}
		
		//printll(f);
		int count = check(f,l);
		printf("%d\n",count);
	}
	return 0;
}
