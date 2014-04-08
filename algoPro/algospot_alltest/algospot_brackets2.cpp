//#include<iostream>
//#include<fstream>
//#include<string>
//#include<cstring>
//#include<cmath>
//#include<vector>
//#include<algorithm>
//#include<queue>
//#include<stack>
//using namespace std;
//
//ifstream in("input.txt");
//
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
//		stack<char> stk;
//		bool flg = true;
//		int matching = 0;
//		for(int i=0;i<str.length();i++){
//			if(str[i] == '{' || str[i] == '(' ||str[i] == '[' )
//				stk.push(str[i]);
//			else{
//				if(!stk.empty()){
//					char t = stk.top();
//					if((t == '{' && str[i] == '}') || (t == '[' && str[i] == ']') || (t == '(' && str[i] == ')')){
//						matching++;
//						stk.pop();
//					}
//					else{
//						flg = false;
//						break;
//					}
//				}
//				else{
//					flg = false;
//					break;
//				}
//			}
//		}
//		if(flg && (str.length()%2 == 0) &&(str.length()/2 == matching))
//			cout<<"YES"<<endl;
//		else
//			cout<<"NO"<<endl;
//	}
//	return 0;
//}