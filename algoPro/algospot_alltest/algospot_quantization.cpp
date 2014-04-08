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
//const int INF = 987654321;
//
//int n,s;
//vector<int> vt;
//vector<int> ssum;
//vector<int> sqsum;
//int cache[101][11];
//
//int minn(int fro, int to){
//	int summ = ssum[to] - (fro == 0 ? 0 : ssum[fro-1]);
//	int sqsumm = sqsum[to] - (fro == 0 ? 0 : sqsum[fro-1]);
//
//	int mm = int(0.5 + (double)summ/(to-fro+1));
//
//	int rst = sqsumm - 2*mm*summ + mm*mm*(to-fro+1);
//	return rst;
//}
//
//int quantize(int from, int part){
//	if(from >= n) return 0;
//
//	if(part == 0) return INF;
//	int& ret = cache[from][part];
//	if(ret!=-1) return ret;
//	ret = INF;
//	
//	for(int ps = 1; from + ps <=n;ps++){
//		ret = min(ret,minn(from, from+ps-1)+ quantize(from+ps,part-1));
//	}
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
//		cin>>n>>s;
//
//		int a;
//		for(int i=0;i<n;i++){
//			cin>>a;
//			vt.push_back(a);
//		}
//
//		memset(cache,-1,sizeof(cache));
//		sort(vt.begin(),vt.end());
//		ssum = vector<int>(n,0);
//		sqsum = vector<int>(n,0);
//
//		ssum[0] = vt[0];
//		sqsum[0] = vt[0]*vt[0];
//		for(int i=1;i<n;i++){
//			ssum[i] = vt[i]+ssum[i-1];
//			sqsum[i] = vt[i]*vt[i] + sqsum[i-1];
//		}
//		int rst = quantize(0,s);
//
//		cout<<rst<<endl;
//		vt.clear();
//	}
//	return 0;
//}