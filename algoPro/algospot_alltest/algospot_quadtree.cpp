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
//#include<iterator>
//using namespace std;
//
//ifstream in("input.txt");
//string str;
//int pos = 0;
//string quadt(){
//	char h = str[pos];
//	pos++;
//	if(pos > str.length()) return "";
//
//	if(h == 'b'|| h =='w')
//		return string(1,h);
//	string upL = quadt();
//	string upR = quadt();
//	string downL = quadt();
//	string downR = quadt();
//
//	return string("x") + downL + downR + upL + upR;
//}
//
//int main(){
//#ifdef _CONSOLE    
//	freopen("input.txt","r", stdin);
//	//	freopen("output.txt","w+", stdout);
//#endif
//	int tc;
//	cin>>tc;
//	while(tc--){
//		
//		cin>>str;
//		pos = 0;
//		cout<<quadt()<<endl;		
//	}
//	return 0;
//}