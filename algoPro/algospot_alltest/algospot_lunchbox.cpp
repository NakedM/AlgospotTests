//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//
//using namespace std;
//
//int main(){
//
//	int tc;
//	cin>>tc;
//
//	while(tc--){
//		int n;
//		cin>>n;
//		int m[10001] = {0,},e[10001]={0,};
//
//		for(int i=0;i<n;i++)
//			cin>>m[i];
//		for(int i=0;i<n;i++)
//			cin>>e[i];
//		vector<pair<int,int>> vt;
//		for(int i=0;i<n;i++)
//			vt.push_back(make_pair(e[i],i));
//
//		sort(vt.begin(),vt.end());
//		reverse(vt.begin(),vt.end());
//		int rst =0;
//		int mw=0;
//		int t;
//		for(int i=0;i<n;i++)
//		{
//			t=vt[i].second;
//			mw+=m[t];
//			rst = max(rst,mw+e[t]);
//		}
//
//		cout<<rst<<endl;	
//
//	}
//
//	return 0;
//}