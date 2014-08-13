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
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int> > pann(n, vector<int>(m, -1));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> pann[i][j];
			}
		}

		int sum = 0;
		for (int j = 0; j < m; j++){
			int count = 0;
			for (int i = n - 1; i >= 0; i--){
				if (pann[i][j] == 1){
					sum += ((n - 1) - i - count);
					count++;
				}
			}
		}

		cout << sum << endl;


	}
	return 0;
}