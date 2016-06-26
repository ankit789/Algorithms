#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long 
ll int m[100001],c[100001];
struct hash{
	double x,y;
	int count;
};
struct hash *hashmap[1000000];
int hsc=0;
struct hash* findhash(double x,double y){
	int i,j;
	for(i=0;i<hsc;i++){
		if(hashmap[i]->x==x && hashmap[i]->y==y){
			return hashmap[i];
		}
	}
	return NULL;
}
void insert(double x,double y){
	struct hash *temp;
	temp = findhash(x,y);
	if(temp){
		(temp->count)++;
		//printf("Incremented: %lf -- %lf\n",temp->x,temp->y);
	}
	else{
		struct hash *t=(struct hash*)malloc(sizeof(struct hash));
		t->x=x;
		t->y=y;
		t->count=1;
		hashmap[hsc]=t;
		//printf("Inserted: %lf -- %lf\n",hashmap[hsc]->x,hashmap[hsc]->y);
		hsc++;
	}
}
int cmp(const void *a,const void *b){
	struct hash *p,*q;
	p=(struct hash*)a;
	q=(struct hash*)b;
	
	return (p->y - q->y);
}

void quicksort(struct hash **x,int first,int last){
	
    int pivot,j,i;
    struct hash *temp;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]->y <= x[pivot]->y &&i<last)
                 i++;
             while(x[j]->y >x[pivot]->y)
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

int main(){
	ll int i,j,n,t,k,count=0;
	double x,y;
	//struct hash hs;
	scanf("%lld%lld",&n,&k);
	for(i=0;i<n;i++){
		scanf("%lld%lld",&m[i],&c[i]);
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(m[i]!=m[j]){
				x= (float)(c[i]-c[j])/(m[j]-m[i]);
				y = m[j]*x+c[j];
				insert(x,y);
			}
		}
	}
	/*
	for(i=0;i<hsc;i++){
		printf("%lf -- %lf %d\n",hashmap[i]->x,hashmap[i]->y,hashmap[i]->count);
	}
	*/
	//qsort(hashmap,hsc,sizeof(struct hash*),cmp);
	quicksort(hashmap,0,hsc-1);
	
	ll int sum=0;
	/*
	printf("Count: %d\n",hsc);
	
	for(i=0;i<hsc;i++){
		printf("%lf -- %lf %d\n",hashmap[i]->x,hashmap[i]->y,hashmap[i]->count);
	}
	*/
	i=0;
	
	while(sum<=k && i<hsc){
		sum+=hashmap[i]->count;
		i++;
	}
	//printf("%lf\n",hashmap[i-1]->y);
	
	if(i==hsc)
	printf("%lf\n",hashmap[i-1]->y);
	else{
		printf("%lf\n",hashmap[i-2]->y);
	}
	
	return 0;
}
