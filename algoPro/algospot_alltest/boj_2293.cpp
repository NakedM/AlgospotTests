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
	vector<long long> results(10001,0);
	for (int i = 0; i < n; ++i){
		cin >> coins[i];
	}
	
	results[0] = 1;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < k+1; j++){
			if (j >= coins[i])
				results[j] += results[j - coins[i]];
		}
	}

	cout << results[k] << endl;

	return 0;
}