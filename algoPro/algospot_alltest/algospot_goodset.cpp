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
		vector<bool> vc(m+1, false);

		bool flg = true;
		for (int i = 0; i < n; i++){
			int k;
			cin >> k;
			if (k == m || k == 0){
				flg = false;
			}
			for (int j = 0; j<k; j++){
				int h;
				cin >> h;
				vc[h] = true;
			}
		}

		if (flg){
			for (int i = 1; i < m + 1; i++)
				flg &= vc[i];
		}

		if (flg)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}
	return 0;
}