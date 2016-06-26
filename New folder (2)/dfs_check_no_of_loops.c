#include<stdio.h>
#include<stdlib.h>

#define white 0
#define gray 1
#define black 2
#define SIZE 100

typedef struct node{
	int d,f,color,parent;
}node;

FILE *fp;
int **a,time,n;
node *s;
void read_inputmatrix(int n);
int dfs_visit(int i);
int dfs();
int no_of_loops=0;


int main(){
	int i,j;
	printf("Enter no. of nodes: ");
	scanf("%d",&n);
	s=(node*)calloc(n,sizeof(node));
	a = (int**)calloc(sizeof(int*),n);
	for(i=0; i<n ; i++)
	{
		a[i] = (int*)calloc(sizeof(int),n);
	} 
	//read_inputmatrix(n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	dfs();
	printf("No. of Loops: %d\n",no_of_loops);
	return 0;
}
/*
void read_inputmatrix(int n)
{
	int i,j,v;  
	//srand((unsigned int) time(0) + getpid());

	fp = fopen("matrix_read.txt","w");
	if(fp == NULL)
	{	
		printf("\n1. file graph_matrixinput.txt does not exist");
		exit(1);
	}
	
	for (i = 0; i <n; ++i)
    	{
      		for (j = 0; j < n; ++j){
				v = rand() % 2;
				if(i==j){
					a[i][j]=0;
					v=0;
				}
				else
				a[i][j] = v;
				fprintf(fp,"%u",v);
				fprintf(fp,"%c",'\t');
			}
			fprintf(fp,"%c",'\n');
	}
	fclose(fp);

}
*/
int dfs_visit(int i){
	int v,j;
	time=time+1;
	s[i].d=time;
	s[i].color=gray;
	for(j=0;j<n;j++){
		//v=a[i][j];
		if(a[i][j]!=0 && s[j].color==gray){
			no_of_loops++;
			printf("Loop b/w node %d and node %d\n",i,j);
		}
		if(s[j].color==white && a[i][j]!=0){
			s[j].parent=i;
			dfs_visit(j);
		}
	}
	s[i].color=black;
	time++;
	s[i].f=time;
	printf("  %d   %d -- %d\n",i,s[i].d,s[i].f);
}
int dfs(){
	int i,j;
	for(i=0;i<n;i++){
		s[i].color=white;
		s[i].parent=-1;	
	}
	time=0;
	dfs_visit(3);
	for(i=0;i<n;i++){
		if(s[i].color==white){
			printf("----------------------------------\n");
			dfs_visit(i);
			
		}
	}
}
