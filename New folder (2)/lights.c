#include<stdio.h>
#include<stdlib.h>
#define long long int ll
#define M 1000001
struct node{
	int val,index;
	struct node *r;
};
int *queue,*visited,f=-1,r=-1;
void insert(int i){
	if(f==-1)
	f++;
	queue[++r]=i;
}
int delete(){
	int x=queue[f];
	f++;
	return x;
}
void bfs(struct node *a,int p,int n,int *count){
	f=-1;r=-1;
	queue=(int*)malloc(n*sizeof(int));
	insert(p);
	while(f!=-1){
		int i=delete();
		if(a[i].val==0){
			*count++;
		}
		struct node *curr;
		for(curr=a[i].r;curr!=NULL;curr=curr->r){
			if(!visited[curr->index]){
				curr->val=1;
				visited[curr->index]=1;
				insert(curr->index);
			}
		}
	}
}
int main(){
	int i,j,n,d,x,y,t,count=0;
	scanf("%d",&t);
	
	while(t--){
		scanf("%d",&n);
		int m[n],p[n+1],q[n+1];
		struct node *a=(struct node*)malloc((n+1)*sizeof(struct node));
		for(i=1;i<=n;i++){
			scanf("%d",&a[i].val);
			a[i].index=i;
			q[i]=0;
		}
		
		visited=(int*)calloc(n+1,sizeof(int));
		for(i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			struct node *temp=(struct node*)malloc(sizeof(struct node));
			temp->index=y;
			temp->r=NULL;
			printf("hi....\n");
			struct node *curr=&a[x];
			printf("Hello....\n");
			while(curr->r)
				curr=curr->r;
			curr->r=temp;
				
			q[x]++;
			q[y]++;	
		}
		count=0;
		int max=-1;
		for(i=1;i<=n;i++){
			if(q[i]>max)
			max=i;
		}
		bfs(a,max,n,&count);
		for(i=1;i<=n;i++){
			if(visited[i]==0){
				insert(i);
				bfs(a,i,n,&count);
			}
			
		}
		printf("%d\n",count);
	}
	return 0;
}
