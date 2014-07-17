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
const int MOD = 10000000;
vector<vector<int>> cache;


int poly(int n, int firstline){
	if (n == firstline)
		return 1;

	int& ret = cache[n][firstline];
	if (ret != -1)
		return ret;
	ret = 0;

	for (int second = 1; second <= n - firstline; second++)
	{
		int slide = second + firstline - 1;
		slide *= poly(n - firstline, second);
		slide %= MOD;
		ret += slide;
		ret %= MOD;
	}

	return ret;

}


int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	
#endif
	int tc;
	cin >> tc;
	while (tc--){
		int n;
		cin >> n;

		vector<int> tmp(n + 1, -1);
		
		for (int i = 0; i < n + 1; i++)
			cache.push_back(tmp);

		int result = 0;
		for (int i = 1; i < n + 1; i++){
			result += poly(n, i);
			result %= MOD;
		}
		cout << result << endl;


		cache.clear();
	}
	return 0;
}