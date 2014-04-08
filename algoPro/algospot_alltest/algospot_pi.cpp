//#include<iostream>
//#include<fstream>
//#include<string>
//#include<cstring>
//#include<cmath>
//#include<vector>
//#include<algorithm>
//#include<queue>
//#include<limits>
//#include<bitset>
//using namespace std;
//
//ifstream in("input.txt");
//
//int cache[10002];
//string str;
//const int INF = 987654321;
//
//int level(int s,int len){
//	bool l1 = true;
//	bool l2 = true;
//	bool l4 = true;
//	bool l5 = true;
//
//	for(int i=1;i<len;i++){
//		if(str[s+i-1] != str[s+i])
//			l1=false;
//	}
//	if(l1) return 1;		
//	for(int i=2;i<len;i++){
//		if(str[s+i-2] != str[s+i])
//			l4=false;
//	}
//	if(l4) return 4;
//	int t = str[s+1] - str[s];
//	for(int i=1;i<len;i++){
//		if(abs(t) != 1 || str[s+i] - str[s+i-1] != t)
//			l2=false;
//	}
//	if(l2) return 2;
//	for(int i=2;i<len;i++){
//		if(str[s+i] - str[s+i-1] != str[s+i-1] - str[s+i-2])
//			l5=false;
//	}
//	if(l5) return 5;
//
//	return 10;
//}
//
//
//int chkPi(int start){
//	if(start == str.length())
//		return 0;
//	int& ret = cache[start];
//	if(ret != -1) return ret;
//	ret = INF;
//
//	for(int i=3;i<=5;i++){
//		if(i+start <= str.length())
//			ret = min(ret,chkPi(start+i)+level(start,i));
//	}
//
//	return ret;
//}
//
//int main(){
//#ifdef _CONSOLE    
//	freopen("input.txt","r", stdin);
//	
//#endif
//	int tc;
//	cin>>tc;
//	while(tc--){		
//		cin>>str;
//		memset(cache,-1,sizeof(cache));	
//
//		cout<<chkPi(0)<<endl;
//	}
//	return 0;
//}