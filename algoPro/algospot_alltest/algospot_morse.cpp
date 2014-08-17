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
const int MAXX = 1000000000 + 100;
int bino[201][201];

void calcBino(){
	memset(bino, 0, sizeof(bino));

	for (int i = 0; i <= 200; i++){
		bino[i][0] = bino[i][i] = 1;
		for (int j = 1; j < i; j++){
			bino[i][j] = min(MAXX, bino[i - 1][j - 1] + bino[i - 1][j]);
		}
	}

}

string kth(int n, int m, int skip){
	if (n == 0) return string(m, 'o');
	if (skip < bino[n + m - 1][n - 1])
		return "-" + kth(n - 1, m, skip);
	return "o" + kth(n, m - 1, skip - bino[n + m - 1][n - 1]);

}

int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	calcBino();
	while (tc--){
		int n, m, k;
		cin >> n >> m >> k;
		
		string str = kth(n, m, k-1);
		cout << str << endl;

	}
	return 0;
}