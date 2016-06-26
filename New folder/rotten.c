#include<stdio.h>
#include<stdlib.h>

struct pair{
	int x,y;
};
struct pair queue[100];
int f=-1,r=-1;

int isempty(){
	if(f>r){
		return 1;
	}
	return 0;
}

void insert(struct pair a){
	if(f==-1) f=0;
	r++;
	queue[r]=a;
}
struct pair pop(){
	struct pair a = queue[f];
	f++;
	return a;
}
int isvalid(int x,int y,int m,int n){
	printf("X: %d Y: %d\n",x,y);
	return (x>=0 && y>=0 && x<m && y<n);
}
int isarg(struct pair temp){
	if(temp.x==-1 && temp.y==-1){
		return 1;
	}
	return 0;
}
int checkall(int m,int n,int mat[][n]){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(mat[i][j]==1){
				return 1;
			}
		}
	}
	return 0;
}
void printq(){
	int i;
	printf("Queue: ");
	for(i=f;i<=r;i++)
	printf("%d -- %d\n",queue[i].x,queue[i].y);
	
}
int findrotten(int m,int n,int mat[][n]){
	struct pair temp,p,curr;
	temp.x=-1;temp.y=-1;
	int i,j,k;
	int ans=0,flag=0;
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(mat[i][j]==2){
				printf("Here Insert\n");
				p.x=i;p.y=j;
				insert(p);
			}
		}
	}
	
	insert(temp);
	
	printf("r: %d f: %d\n",r,f);
	printq();
	
	while(!isempty()){
		curr=pop();
		printf("Curr: %d %d\n",curr.x,curr.y);
		//printq();
		while(!isarg(curr)){
			
			//printq();
			printf("Curr: %d %d\n",curr.x,curr.y);
			if(isvalid((curr.x)+1,curr.y,m,n) && mat[(curr.x)+1][curr.y]==1 ){
				printf("here--\n");
				if(!flag){
					ans++;
					flag=1;
				}
				(curr.x)++;
				mat[curr.x][curr.y]=2;
				insert(curr);
				(curr.x)--;
			}
			if(isvalid((curr.x)-1,curr.y,m,n) && mat[(curr.x)-1][curr.y]==1 ){
				printf("here--\n");
				if(!flag){
					ans++;
					flag=1;
				}
				(curr.x)--;
				mat[curr.x][curr.y]=2;
				insert(curr);
				(curr.x)++;
			}if(isvalid(curr.x,(curr.y)+1,m,n) && mat[curr.x][(curr.y)+1]==1 ){
				printf("here--\n");
				if(!flag){
					ans++;
					flag=1;
				}
				(curr.y)++;
				mat[curr.x][curr.y]=2;
				insert(curr);
				(curr.y)--;
			}if(isvalid(curr.x,(curr.y)-1,m,n) && mat[curr.x][(curr.y)-1]==1 ){
				printf("here--\n");
				if(!flag){
					ans++;
					flag=1;
				}
				(curr.y)--;
				mat[curr.x][curr.y]=2;
				insert(curr);
				(curr.y)++;
			}
			
			curr=pop();			
		}
		if(!isempty()){
			flag=0;
			insert(temp);
		}
	}
	printf("Final Matrix: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
	printf("Ans: %d\n",ans);
	if(checkall(m,n,mat)){
		ans=0;
	}
	printf("%d\n",ans);
}
int main(){
	int m=4,n=4,i,j;
	int mat[4][4]= {1,0,1,1,
					1,2,1,1,
					0,1,0,1,
					1,2,1,1};
	
	//printf("%d")
	findrotten(m,n,mat);
}
