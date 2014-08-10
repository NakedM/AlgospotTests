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

	int xx[4] = { -1, -1, 1, 1 };
	int yy[4] = { 0, -1, -1, 0 };
	int tc;
	cin >> tc;
	while (tc--){
		int n, m;
		cin >> n >> m;

		vector<vector<int> > classs(n, vector<int>(m, 1));

		char ch;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> ch;
				if (ch == 'x')
					classs[i][j] = 0;
			}
		}

		vector<int> result(m, 0);

		for (int s = 0; s < m; s++){
			vector<vector<int> > pann = classs;
			for (int j = s; j < m; j++){
				for (int i = n-1; i >= 0; i--){
					if (pann[i][j] == 1){
						result[s] += pann[i][j];
						for (int h = 0; h < 4; h++){
							if (xx[h] + j < 0 || yy[h] + i < 0 || xx[h] + j >= m || yy[h] >= n)
								continue;
							pann[yy[h] + i][xx[h] + j] = 0;
						}
					}
				}
				cout << s << endl;
				for (int p = 0; p < n; p++){
					for (int q = 0; q < m; q++){
						cout << pann[p][q] << " ";
					}
					cout << endl;
				}
				cout << endl;
			}
			for (int j = 0; j < s; j++){
				for (int i = n - 1; i >= 0; i--){
					if (pann[i][j] == 1){
						result[s] += pann[i][j];
						for (int h = 0; h < 4; h++){
							if (xx[h] + j < 0 || yy[h] + i < 0 || xx[h] + j >= m || yy[h] >= n)
								continue;
							pann[yy[h] + i][xx[h] + j] = 0;
						}
					}
				}
			}
		}
	
		cout << *max_element(result.begin(), result.end()) << endl;
	}
	return 0;
}