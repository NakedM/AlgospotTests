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
//double cache[1001][1001];
//int n,m;
//const double sunny = 0.25;
//const double rainy  = 0.75;
//
//double snailing(int dday, int sun, int rain, int high){
//	if(high>=n)
//		return 1.0;
//	if(dday>=m)
//		return 0.0;
//
//	double& ret = cache[sun][rain];
//	if(ret !=-1.0) return ret;
//	ret = 0.0;
//
//	ret = sunny*snailing(dday+1,sun+1,rain,high+1)+rainy*snailing(dday+1,sun,rain+1,high+2);
//	return ret;
//}
//int main(){
//#ifdef _CONSOLE    
//	freopen("input.txt","r", stdin);
//	//	freopen("output.txt","w+", stdout);
//#endif
//	int tc;
//	cin>>tc;
//	while(tc--){		
//		cin>>n>>m;
//
//		for(int i=0;i<1001;i++){
//			for(int j=0;j<1001;j++){
//				cache[i][j] = -1.0;
//			}
//		}
//
//		double rst;
//		rst = snailing(0,0,0,0);
//
//		cout.precision(10);
//		cout<<fixed<<rst<<endl;
//	}
//	return 0;
//}