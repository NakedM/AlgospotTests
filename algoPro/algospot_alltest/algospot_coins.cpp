//#include<iostream>
//#include<fstream>
//#include<string>
//#include<cstring>
//#include<cmath>
//#include<vector>
//#include<algorithm>
//#include<queue>
//#include<limits>
//using namespace std;
//
//ifstream in("input.txt");
//vector<int> vt;
//long long alcnt[101][5001];
//const long long MOD = 1000000007;
//
//long long countC(long long kindM, long long remainM){
//	if(remainM < 0)


//		return 0;
//	if(remainM == 0)
//		return 1;
//
//	long long& ret = alcnt[kindM][remainM];
//	if(ret !=-1) return ret;
//	ret = 0;
//	
//	for(int i=kindM;i<vt.size();i++){
//		if(remainM - vt[i] < 0)
//			break;
//		ret = (ret+countC(i,remainM - vt[i])+MOD)%MOD;
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
//		int money, n;
//		cin>>money>>n;
//
//		int a;
//		for(int i=0;i<n;i++){
//			cin>>a;
//			vt.push_back(a);
//		}
//
//		for(int i=0;i<101;i++)
//			memset(alcnt[i],-1,sizeof(alcnt[i]));
//
//		//sort(vt.begin(),vt.end());
//		long long rst = countC(0,money);
//		cout<<rst<<endl;
//
//		vt.clear();
//	}
//	return 0;
//}