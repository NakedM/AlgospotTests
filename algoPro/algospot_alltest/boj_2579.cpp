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

int n;
vector<int> vc;
vector<vector<int> > sco;

void dp(int p, int c, int s){
	if (p > n)
		return;
	if (c > 2)
		return;

	if (sco[c][p] >= vc[p] + s)
		return;
	sco[c][p] = vc[p] + s;

	dp(p + 3, 1, sco[c][p]);
	dp(p + 2, 1, sco[c][p]);
	dp(p + 1, c + 1, sco[c][p]);

	return;
}

int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
#endif
	cin >> n;
	vc = vector<int>(n+1);
	sco = vector<vector<int> > (3, vector<int>(n+1, -1));
	vc[0] = 0;
	for (int i = 1; i < n+1; i++)
		cin >> vc[i];

	dp(0, 0, 0);

	int sm = max(max(sco[1][n - 3], sco[1][n - 2]), max(sco[1][n - 1], sco[1][n]));
	sm = max(sm,max(max(sco[2][n - 3], sco[2][n - 2]), max(sco[2][n - 1], sco[2][n])));
	cout << sm<< endl;

	return 0;
}