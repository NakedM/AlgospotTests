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

vector<vector<int> > vc;
vector<int> ans;

int cutting(int n, int y, int x){
	if (n == 1)
		return vc[y][x];

	n /= 2;
	int s =
		cutting(n, y, x) +
		cutting(n, y, x + n) +
		cutting(n, y + n, x) +
		cutting(n, y + n, x + n);

	int c = 4;
	bool flg = true;
	while (s > 4){
		s -= 5;
		c--;
		flg = false;
	}

	if (flg && s % 4 == 0)
		return s / 4;
	else
	{
		ans[0] += c - s;
		ans[1] += s;
		return 5;
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	ans = vector<int>(2, 0);
	vc = vector<vector<int> >(n, vector<int>(n));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> vc[i][j];
		}
	}

	cutting(n, 0, 0);	
	cout << ans[0]<<endl<< ans[1] << endl;

	return 0;
}