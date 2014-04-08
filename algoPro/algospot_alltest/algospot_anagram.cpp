//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int main(){
//	int tc;
//	cin>>tc;
//
//	while(tc--){
//		string str, psw;
//		cin>>str>>psw;
//		
//		int len = str.length();
//		vector<int> strvt(len);
//		int len2 = psw.length();
//		vector<int> pswvt(len2);
//
//		for(int i=0;i<len;i++){
//			strvt[i] = str[i]-'A';
//		}
//
//		for(int i=0;i<len2;i++){
//			pswvt[i] = psw[i]-'A';
//		}
//
//		sort(strvt.begin(),strvt.end());
//		sort(pswvt.begin(),pswvt.end());
//
//		if(strvt == pswvt && str!=psw)
//			cout<<"Yes"<<endl;
//		else
//			cout<<"No."<<endl;
//	}
//	return 0;
//}