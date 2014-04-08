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
//string str;
//
//int cache[101][101];
//
//int bracket(int fr, int to){
//	if(fr>=to) return 0;
//	
//	int& ret = cache[fr][to];
//	if(ret != -1) return ret;
//	ret = 0;
//
//	for(int i=fr;i<=to-1;i++){
//		for(int j = i+1;j<=to;j++){
//			if(str[i] == '('){
//				if(str[j] == ')')
//					ret = max(ret,2+bracket(i+1,j-1)+bracket(j+1,to));
//			}
//			if(str[i] == '['){
//				if(str[j] == ']')
//					ret = max(ret,2+bracket(i+1,j-1)+bracket(j+1,to));
//			}
//		}
//	}
//
//	return ret;
//}
//
//int main(){
//#ifdef _CONSOLE    
//	freopen("input.txt","r", stdin);
//	//	freopen("output.txt","w+", stdout);
//#endif
//	//int tc;
//	//cin>>tc;
//	while(1){
//		memset(cache,-1,sizeof(cache));
//		cin>>str;
//		
//		if(str=="end")
//			break;
//
//		int rst = bracket(0,str.length()-1);
//
//		cout<<rst<<endl;
//	}
//	return 0;
//}