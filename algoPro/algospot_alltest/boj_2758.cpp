#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits>
#include<bitset>
using namespace std;

#pragma warning (disable:4996)
ifstream in("input.txt");

long long cache[11][2001];
long long cache2[11][2001];


long long rotto(int cn, int cm){
	//if (cn == n && cm <= m){
	if (cn == 10 && cm<= 2000){
		//cout << cm << " ";+6+6
		return 1;
	}
	if (cn > 10 || cm > 2000)
		return 0;
	
	long long& ret = cache[cn][cm];
	if (ret != -1)		
		return ret;
	

	ret = 0;
	for (int i = cm * 2; i <= 2000; i++){	
		ret += rotto(cn + 1, i);
	}

	return ret;
}

void rotto3(){

	memset(cache2, 0, sizeof(cache2));
	
	//for(int i= 0;i<2000;i++)
	//	cache2[0][i] = 1;
	cache2[0][0] = 1;
	for (int sel = 1; sel <= 10; sel++){
		for (int num = 1; num <= 2000; num++){
			int t = num / 2;
			for (int i = 0; i <= t; i++){
				cache2[sel][num] += cache2[sel - 1][i];
			}
		}
	}
}


//
//long long rotto2(long long s){
//	vector<long long> maxx(n);
//	vector<long long> minn(n);
//	vector<long long> dis(n);
//
//	int tm = m;
//	for (int i = n - 1; i >= 0; i--){
//		maxx[i] = tm;
//		tm /= 2;
//	}
//	tm = 1;
//	for (int i = 0; i < n; i++){
//		minn[i] = tm;
//		tm *= 2;
//	}
//	for (int i = 0; i < n; i++){
//		dis[i] = maxx[i] - minn[i] + 1;
//	}
//
//	bool read = false;
//	vector<long long> vc[2];
//	for (int i = 0; i<dis[n - 1]; i++)
//		vc[0].push_back(1);
//	//vector<long long> write;
//
//	for (int i = n-2; i >=0 ; i--){
//		
//		vc[!read] = vector<long long>(dis[i], 0);
//		if (dis[i] * 2 > dis[i + 1]){
//			for (long long k = dis[i] - 1; k >= 0; k--){
//				for (long long h = 0; h < k * 2 + 1; h++)
//					vc[!read][k] += vc[read][h];
//			}
//		}
//		else{
//			for (long long k = dis[i] - 1; k >= 0; k--){
//				for (long long h = 0; h < k * 2 + 2; h++)
//					vc[!read][k] += vc[read][h];
//			}
//		}
//		//vc[read].clear();
//		read = !read;
//	}
//
//	int wsz = vc[!read].size();
//	long long result = 0;
//
//	for (int i = 0; i < wsz; i++)
//		result += vc[!read][i];
//
//	return result;
//}

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	
	memset(cache, -1, sizeof(cache));

	int lim = 2000;
	for (int i = 0; i < 10 - 1; i++)
		lim /= 2;

	long long result = 0;
	for (int i = 1; i <= lim; i++){
		result += rotto(1, i);
	}
	cout << result << endl;

	rotto3();	
	while (tc--){
		int n, m;
		cin >> n >> m;

		
		long long result2 = 0;

		for (int i = 1; i <= m; i++)
			result2 += cache2[n][i];
		cout << result2 << endl;
		

		//result = 0;
		////for (int i = 1; i <= lim; i++)
		//result += rotto2(1);

		//cout << result << endl;

	}
	return 0;
}