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
//		vector<vector<int>> vt(n+1);
//		vector<vector<int>> psum(n+1);
//		
//		int a;
//		for(int i=0;i<n+1;i++){
//			vt[i].push_back(0);
//			psum[i].push_back(0);
//		}
//		for(int i=1;i<n+1;i++){
//			vt[i].push_back(0);
//			for(int j=0;j<n;j++){
//				cin>>a;
//				vt[i].push_back(a);
//			}
//		}
//
//		for(int i=1;i<n+1;i++){
//			psum[i].push_back(0);
//			for(int j=1;j<n+1;j++){
//				psum[i].push_back(vt[i][j]+psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]);
//			}
//		}
//
//		int mxsum = psum[1][1];
//
//
//
//	}
//	return 0;
//}