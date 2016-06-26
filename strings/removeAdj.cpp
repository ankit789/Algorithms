#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int l = s.size();
	for(int i=0;i<l-1;){
		if(s[i]==s[i+1]){
			int j=i+1;
			while(s[j]==s[i]){
				s.erase(s.begin()+j);
				l--;
			}
			s.erase(s.begin()+i);
			l--;
			if(i>0)
			i--;
		}
		else{
			i++;
		}
	}
	cout<<"Output: "<<s<<endl;
	return 0;
}
