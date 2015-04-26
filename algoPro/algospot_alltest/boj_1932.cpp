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

const int INF = 987654321;

#pragma warning (disable:4996)
ifstream in("input.txt");

int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	vector<vector<int> > vc(n + 1, vector<int>(n + 1, 0));
	vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i < n + 1; i++){
		for (int j = 1; j < i+1; j++){
			cin >> vc[i][j];
		}
	}
	dp = vc;

	for (int i = n; i > 0; i--){
		for (int j = i; j >0; j--){
			dp[i - 1][j] = max(dp[i - 1][j], vc[i - 1][j] + dp[i][j]);
			dp[i - 1][j-1] = max(dp[i - 1][j-1], vc[i - 1][j-1] + dp[i][j]);
		}
	}

	cout << dp[0][0] << endl;

	return 0;
}