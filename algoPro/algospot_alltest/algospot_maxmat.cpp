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

#pragma warning (disable:4996)

ifstream in("input.txt");

int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _CONSOLE    
	freopen("input.txt","r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin>>tc;
	while(tc--){
		int n;
		cin>>n;
		vector<vector<int> > vt(n + 1, vector<int>(n + 1, 0));
		vector<vector<int> > psum(n+1, vector<int>(n+1, 0));
		vector<vector<int> > ppp(n + 1, vector<int>(n + 1, 0));
		
		int a;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				cin >> a;
				vt[i][j] = a;
			}
		}

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				psum[i][j] = vt[i][j] + psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
			}
		}


		int result = -987654321;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				for (int u = 0; u < i; u++){
					for (int v = 0; v < j; v++){
						result = max(result, psum[i][j] - psum[i][v] - psum[u][j] + psum[u][v]);
					}
				}
			}			
		}

		cout << result << endl;

	}
	return 0;
}