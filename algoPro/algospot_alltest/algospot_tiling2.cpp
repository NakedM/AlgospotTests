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
//long long cache[101];
//const int MOD = 1000000007;
//
//long long tiling(int a){
//	if(a<=0)
//		return 1;
//	if(a==1)
//		return 1;
//	if(a==2)
//		return 2;
//	long long & ret = cache[a];
//	if(ret != -1) return ret;
//	ret = 0;
//	ret = (tiling(a-1)+tiling(a-2)+MOD)%MOD;
//	
//	return ret;
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
//		int n;
//		cin>>n;
//		
//		for(int i=0;i<101;i++){
//			cache[i] = -1;
//		}
//		
//		int rst = tiling(n);
//		cout<<rst<<endl;
//	}
//	return 0;
//}