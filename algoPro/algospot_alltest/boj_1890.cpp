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
	vector<vector<int> > pann(n, vector<int>(n));
	vector<vector<long long> > path(n, vector<long long>(n, 0));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> pann[i][j];
		}
	}
	path[0][0] = 1;
	

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (pann[i][j] == 0)
				break;
			if (path[i][j] != 0){
				if (j + pann[i][j] < n)
					path[i][j + pann[i][j]] += path[i][j];
				if (i + pann[i][j] < n)
					path[i+pann[i][j]][j] += path[i][j];
			}
		}
	}

	cout << path[n - 1][n - 1] << endl;

	return 0;
}