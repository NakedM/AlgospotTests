//#include<iostream>
//#include<fstream>
//#include<string>
//#include<cstring>
//#include<cmath>
//#include<vector>
//#include<algorithm>
//#include<queue>
//#include<limits>
//using namespace std;
//
//ifstream in("input.txt");
//
//int main(){
//#ifdef _CONSOLE    
//	freopen("input.txt","r", stdin);
//	//	freopen("output.txt","w+", stdout);
//#endif
//	//int tc;
//	//cin>>tc;
//	
//
//	string div61 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
//	while(1){
//		string str;
//		cin>>str;
//		if(str=="end") break;
//		long int sum = 0;
//		
//		for(int i=0;i<str.length();i++){
//			int t;
//			for(int pos =0 ; pos<div61.length();pos++){
//				if(str[i] == div61[pos])
//					t = pos;				
//			}
//			sum += t;
//		}
//		if(sum%61 == 0)
//			cout<<"yes"<<endl;
//		else
//			cout<<"no"<<endl;
//	}
//	return 0;
//}