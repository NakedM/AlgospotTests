#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits>
#include<bitset>
using namespace std;

ifstream in("input.txt");
int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt","w+", stdout);
#endif
	//std::ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--){
		int n, k, r;
		cin >> n >> k >> r;
		vector<int> ships(k+1, -1); //x1,x2,y1,y2,w
		vector<bool> livingShips(k + 1, true);

		vector < vector<pair<int, int> > > xrange(k+1);
		vector < vector<pair<int, int> > > yrange(k+1);

		const int MAXK = k+1;

		int x1, y1, x2, y2, w;
		for (int i = 1; i < k + 1; i++){
			cin >> x1 >> y1 >> x2 >> y2 >> w;
			ships[i] = w;
			
			for (int j = min(x1, x2); j <= max(x1, x2); j++)
				xrange[j%MAXK].push_back(make_pair(j / MAXK,i));

			for (int j = min(y1, y2); j <= max(y1, y2); j++)
				yrange[j%MAXK].push_back(make_pair(j / MAXK, i));

			
		}
		for (int i = 0; i < r; i++){
			int a, b;
			cin >> a >> b;

			int maxkill = 0;
			if (b == 0){
				int remain = a % MAXK;
				int val = a / MAXK;
				int sz = yrange[a%MAXK].size();

				for (int j = 0; j < sz; j++){
					if (val == yrange[remain][j].first){						
							int pos = yrange[a%MAXK][j].second;
							if (!livingShips[pos])
								continue;

							if (ships[pos] > maxkill)
								maxkill = ships[pos];
							livingShips[pos] = false;
					}
				}
			}
			else{
				int remain = a % MAXK;
				int val = a / MAXK;
				int sz = xrange[remain].size();
				
				for (int j = 0; j < sz; j++){
					if (val == xrange[remain][j].first){
						int pos = xrange[remain][j].second;
						if (!livingShips[pos])
							continue;

						if (ships[pos] > maxkill)
							maxkill = ships[pos];
						livingShips[pos] = false;
					}
				}
			}

			cout << maxkill << endl;
		}
	}
	return 0;
}
