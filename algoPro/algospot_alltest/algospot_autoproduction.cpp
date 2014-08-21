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
		int n;
		cin >> n;
		vector<int> need(n, 0);
		vector<vector<int> > pocket(n);
		vector<vector<int> > psum(n);
		for (int i = 0; i < n; i++){
			int ne, m;
			cin >> ne >> m;
			need[i] = ne;

			for (int j = 0; j < m; j++){
				int a;
				cin >> a;
				pocket[i].push_back(a);
			}
			sort(pocket[i].begin(), pocket[i].end());
			reverse(pocket[i].begin(), pocket[i].end());
			psum[i].push_back(pocket[i][0]);
			for (int j = 1; j < m; j++)
				psum[i].push_back(psum[i][j - 1] + pocket[i][j]);
		}
		

		for (int i = 0; i < n; i++){
			int sz = psum[i].size();
			for (int j = 0; j < sz; j++){
				psum[i][j] /= need[i];
			}
		}


		vector<int> curpos(n, 0);
		const int LIM = 10;
		int count = n;
		int result = -1;

		while (count <= LIM){
			int item = -1;
			int minn = 100000;
			for (int i = 0; i < n; i++){							
				if (psum[i][curpos[i]] < minn){
					minn = psum[i][curpos[i]];
					item = i;
				}
			}
			curpos[item]++;			
			count++;
			result = minn;
			if (curpos[item] >= psum[item].size())
				break;
		} 

		cout << result << endl;

	}
	return 0;
}