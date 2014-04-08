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
//		vector<int> vt;
//		vector<int> psum(n,0);
//
//		int a;
//		for(int i=0;i<n;i++){
//			cin>>a;
//			vt.push_back(a);
//		}
//
//		psum[0] = vt[0];
//		int mxsum = vt[0];
//		for(int i=1;i<n;i++){
//			if(psum[i-1]>=0)
//				psum[i] = psum[i-1]+vt[i];
//			else
//				psum[i] = vt[i];
//
//			if(psum[i] > mxsum)
//				mxsum = psum[i];
//		}
//
//		cout<<mxsum<<endl;
//	}
//	return 0;
//}