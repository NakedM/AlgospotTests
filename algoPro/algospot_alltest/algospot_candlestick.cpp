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
//int main(){
//#ifdef _CONSOLE    
//	freopen("input.txt","r", stdin);
//	//	freopen("output.txt","w+", stdout);
//#endif
//	int tc;
//	cin>>tc;
//	while(tc--){
//		int n;
//		cin>>n;
//
//		vector<pair<int,int>> vt;
//		int a,b;
//		for(int i=0;i<n;i++){
//			cin>>a>>b;
//			vt.push_back(make_pair(a,b));
//		}
//
//		int low = -1;
//		int high = 100000000;
//		long long mmax = 0;
//		int cnt = 0;
//		for(int i=0;i<n;i++){
//			low = -1;
//			high = 100000000;
//			cnt = 0;
//			for(int j=i;j<n;j++){
//				cnt++;
//				low = max(low,vt[j].first);
//				high = min(high,vt[j].second);
//				long long t = (cnt)*(high-low);
//				mmax = max(mmax,t);
//			}
//		}
//
//		cout<<mmax<<endl;
//
//	}
//	return 0;
//}