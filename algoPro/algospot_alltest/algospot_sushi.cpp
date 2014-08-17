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
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		int n, m;
		cin >> n >> m;

		vector<int> price(n);
		vector<int> prefer(n);

		int memo[201];

		for (int i = 0; i < n; i++){
			int a;
			cin >> a;
			price[i] = a / 100;
			cin >> prefer[i];
		}

		m /= 100;
		memo[0] = 0;
		int res = 0;
		for (int remain = 1; remain <= m; remain++)
		{
			int tmp = 0;
			for (int dish = 0; dish < n; dish++){
				if (remain >= price[dish])
					tmp = max(tmp, memo[(remain - price[dish]) % 201] + prefer[dish]);
				memo[remain % 201] = tmp;
				res = max(res, tmp);
			}
		}

		cout << res << endl;
	}

	
	return 0;
}