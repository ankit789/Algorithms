#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

struct ele{
	int x,y;
};
void findrotten(int r,int c,vector< vector<int> >& mat){
	int i,j;
	queue<ele> q;
	ele temp,curr;
	
	int ans=0,flag=0;
	for(vector< vector<int> >::iterator it=mat.begin();it!=mat.end();it++){
		//if(*it)
	}
	
}
int main(){
	int m,n,c;
	cin >> m >> n;
//	vector<int> v;
	vector< vector<int> > mat(m, vector<int>(n));
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >> c;
			mat.push_back(c);
		}
	}
	
	findrotten(m,n,mat);
	
	
	return 0;
}
