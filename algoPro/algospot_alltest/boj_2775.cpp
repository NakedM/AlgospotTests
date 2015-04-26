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

	vector<vector<long long> > apartment(15, vector<long long>(15, 0));

	for (int j = 0; j < 15; j++){
		apartment[0][j] = j;
	}

	for (int i = 1; i < 15; i++){
		for (int j = 1; j < 15; j++){
			apartment[i][j] = apartment[i][j - 1] + apartment[i - 1][j];
		}
	}

	int tc;
	cin >> tc;
	while (tc--){
		int n, k;
		cin >> n >> k;
		cout << apartment[n][k] << endl;


	}
	return 0;
}