#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<limits>
#include<bitset>
#include<map>
using namespace std;

#pragma warning (disable:4996)
ifstream in("input.txt");

int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
#endif
	int n, k;
	cin >> n >> k;
	vector<int> coins(n);
	vector<int> vals(10001, 123456789);
	
	for (int i = 0; i < n; i++)
		cin >> coins[i];
	vals[0] = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= k; j++){
			if (j - coins[i] < 0) continue;
			vals[j] = min(vals[j], vals[j - coins[i]] + 1);
		}
	}

	cout << vals[k] << endl;

	return 0;
}