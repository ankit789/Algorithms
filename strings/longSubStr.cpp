#include<bits/stdc++.h>
using namespace std;
#define MAX 256
int isValid(int *count,int k){
	int check=0;
	for(int i=0;i<MAX;i++){
		if(count[i]>0){
			check++;
		}
	}
	return check<=k?1:0;
}
int main(){
	string s;
	int k;
	cin>>s>>k;
	//cout<<s<<", k: "<<k<<endl;
	int i,j,n=0;
	int l = s.length();
	int count[MAX];
	memset(count,0,sizeof(count));
	
	for(i=0;i<l;i++){
		if(count[s[i]]==0)
			n++;
		count[s[i]]++;
	}
	if(n<k){
		cout<<"Not enough characters\n";
		exit(1);
	}
	
	memset(count,0,sizeof(count));
	string s1="";
	int currStart=0,currEnd=0;
	//int maxStart=0,maxEnd=0;
	int maxWinSize=INT_MIN;
	int maxWinStart=0;
	
	count[s[0]]++;
	//currEnd++;
	for(i=1;i<l;i++){
		
		//s1.append(s[i]);
		count[s[i]]++;
		currEnd++;
		
		while(!isValid(count,k)){
			count[s[currStart]]--;
			currStart++;	
		}
		if(currEnd-currStart+1 > maxWinSize){
			maxWinSize = currEnd-currStart+1;
			maxWinStart=currStart;
		}
		
	}
	
	cout<<"Max Substring is: "<<s.substr(maxWinStart,maxWinSize)<<" with size of: "<<maxWinSize<<endl;
	return 0;
}
