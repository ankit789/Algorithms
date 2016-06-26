
int Abs(int a){
    return a>0?a:-a;
}
int steps(int x1,int y1,int x2,int y2){
    if(x1==x2 && y1==y2)
    return 0;
    else{
        int min_x=(x2-x1);
        int min_y=(y2-y1);
        int min=Abs(min_x)<Abs(min_y)?Abs(min_x):Abs(min_y);
        
        if(min_x>0) x1+=min;
        else x1-=min;
        
        if(min_y>0) y1+=min;
        else y1-=min;
        
        if(x1==x2 && y1==y2)
        return min;
        
        else if(x1==x2){
            int min_y=Abs(y2-y1);
        }else if(y1==y2){
            min_x=Abs(x2-x1);
        }
        int min2=min_x<min_y?min_x:min_y;
        return min+min2;
    }
}
int coverPoints(int* X, int n1, int* Y, int n2) {
    int i,count=0;
    for(i=0;i<n1-1 && i<n2-1;i++){
        count+=steps(X[i],Y[i],X[i+1],Y[i+1]);
    }
    return count;
}
int main(){
	int a[]={-7,-13},n1=2;
	int b[]={1,-5},n2=2;
	int c = coverPoints(a,n1,b,n2);
	printf("%d\n",c);
	return 0;
}


