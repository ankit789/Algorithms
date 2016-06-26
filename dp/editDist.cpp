#include<iostream>
#include<string>

using namespace std;

int editDist(string str1,string str2,int l1,int l2){
	if(l1==0) return l2;
	if(l2==0) return l1;
	
	if(str1[l1-1]==str2[l2-1]) 
		return editDist(str1,str2,l1-1,l2-1);
		
	return 1+ min(
				editDist(str1,str2,l1,l2-1),
				editDist(str1,str2,l1-1,l2),
				editDist(str1,str2,l1-1,l2-1)
			);
}
int min(int a,int b,int c){
	return (a>b)?(a>c?a:c):(b>c?b:c);
}

int main(){
	string str1,str2;
	cin>>str1;
	cin>>str2;
	int l1,l2;
	l1 = str1.length();
	l2 = str2.length();
	cout<<"Minimum edit distance: "<<editDist(str1,str2,l1,l2)<<endl;
	return 0;
}

