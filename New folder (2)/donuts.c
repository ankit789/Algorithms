#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node *l,*r;
};
void quicksort(int *x,int first,int last){
	
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
	
}
struct node* createnode(int i){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->l=temp->r=NULL;
	temp->val=i;
	return temp;
}
void printll(struct node *l){
	printf("\nLL at this time: ");
	while(l){
		printf("%d",l->val);
		l=l->r;
	}
}
int main(){
	int t,m,n,i,j,*a,count,x=0;
	struct node *l,*head,*last;
	scanf("%d",&t);
	while(t--){
		count=0;
		x=0;
		scanf("%d%d",&n,&m);
		a=(int*)malloc(m*sizeof(int));
		for(i=0;i<m;i++){
			scanf("%d",&a[i]);
			if(a[i]==1){
				x++;
			}
		}
		if(x==m){
			count=floor(x/2);
		}
		else{
			quicksort(a,0,m-1);
			
			
			
			head=createnode(a[0]);
			l=head;
			//last=NULL;
			for(i=1;i<m;i++){
				struct node *temp;
				temp=createnode(a[i]);
				temp->l=l;
				l->r=temp;
				l=l->r;
			}
			last=l;
			//printll(head);
			struct node *t=head;
			while(t!=last){
				//printll(t);
				if(t->val==0){
					t=t->r;
				}
				else{
					(t->val)--;
					int p = last->val+(last->l->val);
				//	printf("\nt: %d last %d last->left: %d p: %d",t->val,last->val,last->l->val,p);
					last=last->l;
					last->r=NULL;
					last->val=p;
					count++;
				}
			//	printll(t);
		}
		}
		printf("%d\n",count);
	}
}
