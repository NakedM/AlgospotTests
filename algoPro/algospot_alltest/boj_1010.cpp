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

int N, M;
long long cache[34][34];

long long dp(int c, int st){
	if (c >= N)
		return 1;

	long long& ret = cache[c][st];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int i = st + 1; i <= M; i++)
		ret += dp(c + 1, i);

	return ret;
}


///������ ����
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
		N = n;
		M = m;

		memset(cache, -1, sizeof(cache));

		long long res = dp(0, 0);
		cout << res << endl;

		int a;
		for (int i = a = 1; i <= n; i++, m--)
			{ a *= m; 
				a /= i; }
		 ///// ���� nCr
		//////������ nPr�� ���ϱ�

		cout << a << endl;



	}
	return 0;
}