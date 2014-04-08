//#include<iostream>
//#include<fstream>
//#include<string>
//#include<cstring>
//#include<cmath>
//#include<vector>
//#include<algorithm>
//#include<queue>
//using namespace std;
//
//ifstream in("input.txt");
//
//int main(){
//#ifdef _CONSOLE    
//	freopen("input.txt","r", stdin);
//	//	freopen("output.txt","w+", stdout);
//#endif
//	int tc;
//	cin>>tc;
//	while(tc--){
//		string str;
//		cin>>str;
//
//		string rst;
//		for(int i=0;i<str.length();i++){
//			if(str[i] == '%'){
//				i+=2;
//				switch(str[i]){
//				case '0' : rst+=' ';
//					break;
//				case '1' : rst+='!';
//					break;
//				case '4' : rst+='$';
//					break;
//				case '5' : rst+='%';
//					break;
//				case '8' : rst+='(';
//					break;
//				case '9' : rst+=')';
//					break;
//				case 'a' : rst+='*';
//					break;
//				default:
//					break;
//				}
//			}
//			else
//			rst += str[i];
//		}
//		cout<<rst<<endl;
//
//	}
//	return 0;
//}