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
//int n;
//int vs,vm;
//vector<int> vt;
//int cache[52][1002];
//
//int turnv(int start,int curv){
//	//cout<<curv<<" ";
//	if(curv <0)
//		return -1;
//	if(curv>vm)
//		return -1;
//	/*if(start ==n && curv == vm)
//	{
//		for(int i=0;i<n+1;i++){
//			for(int j=0;j<vm+1;j++){
//				cache[i][j] = vm;
//			}
//		}
//	}*/
//	if(start>=n)
//		return curv;
//	int& ret = cache[start][curv];
//	if(ret != -2) return ret;
//	ret = 0;
//
//	int pc = turnv(start+1,curv+vt[start]);
//	int mc = turnv(start+1,curv-vt[start]);
//	
//	if(pc == -1 && mc == -1)
//		ret = -1;
//	else
//		ret = max(pc,mc);
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
//		cin>>n;
//		cin>>vs>>vm;
//
//		for(int i=0;i<52;i++){
//			for(int j=0;j<1002;j++){
//				cache[i][j] = -2;
//			}
//		}
//		//memset(cache,-2,sizeof(cache));
//
//		int a;
//		for(int i=0;i<n;i++){
//			cin>>a;
//			vt.push_back(a);
//		}
//
//		int rst;
//		rst = turnv(0,vs);
//
//		cout<<rst<<endl;
//
//		vt.clear();
//	}
//	return 0;
//}