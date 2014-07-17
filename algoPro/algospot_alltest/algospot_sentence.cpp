#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

ifstream in("input.txt");

int main(){
#ifdef _CONSOLE    
	freopen("input.txt","r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int m;
	int n;
	cin>>m;
	cin>>n;
	vector<string> sentence(m);
	string str;
	cin.ignore();
	vector<bool> bolvt;
	for(int i=0;i<m;i++){
		getline(cin,str);
		sentence[i] = str;
		//bolvt.push_back(false);
	}
	vector<string> strvt(n);
	
	for(int i=0;i<n;i++){
		getline(cin,str);
		strvt[i];		
	}
	//sort(sentence.begin(),sentence.end());
	//sort(strvt.begin(),strvt.end());


	cout<<(int)sentence[0].find(strvt[1])<<endl;
	int count =0;

	
	cout<<count<<endl;
	return 0;
}