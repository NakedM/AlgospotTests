#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits>
#include<bitset>
using namespace std;

ifstream in("input.txt");
string fat;
string ma;
vector<int> vt;
vector<int> rstvt;
int main(){
#ifdef _CONSOLE
	freopen("input.txt","r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	//int tc;
	//cin>>tc;
	//while(tc--){
	cin>>fat;
	cin>>ma;
	string str = fat + ma;
	string tmp = str;
	int len = str.length();
	vt = vector<int>(len,0);
	vt[0] = -1;	int j;
	for(int i = 1; i<len;i++){	
		j = vt[i-1]+1;	
		while(str[i] != str[j] && j > 0){
			j = vt[j-1]+1;
		}	
		if(str[j] == str[i]) { 
			vt[i] = j;  	
		}		 	
		else{ vt[i] = -1; }
	}		
	rstvt.push_back(len);
	int pos = vt[len-1];
	while(pos >= 0){	
		rstvt.push_back(pos+1);
		pos = vt[pos];
	}	
	for(int i = rstvt.size()-1;i>=0;i--){
		cout<<rstvt[i];	
		if(i == 0)		
			cout<<endl;	
		else	
			cout<<" ";
	}
	vt.clear();	
	rstvt.clear();
	return 0;
}
