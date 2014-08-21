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

//이분 그래프 이분 매칭 공부하고 다시 풀기

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
		int n, m, p1, p2;
		cin >> n >> m >> p1 >> p2;

		vector<vector<bool> > graph(n+1, vector<bool>(m+1, false));

		int blenkcount = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				char c;
				cin >> c;
				if (c == '0')
					graph[i][j] = true;
				else
					graph[i][j] = false;
				if (graph[i][j])
					blenkcount++;
			}
		}

		if (p1*2 <= p2){
			cout << blenkcount *  p1 << endl;
			continue;
		}

		int arr[2][2] = { { 1, 0 }, { 0, 1 } };
		vector<int> result(2, 0);
		for (int h = 0; h < 2; h++){
			int p1count = 0, p2count = 0;
			vector<vector<bool> > pann = graph;
			
			for (int i = 0; i < n; i++){
				for (int j = 0; j < m; j++){
					if (pann[i][j]){
						int k;
						for (k = 0; k < 2; k++){
							if (pann[i + arr[1][k]][j + arr[0][k]]){
								pann[i + arr[1][k]][j + arr[0][k]] = false;
								p2count++;
								break;
							}
						}
						pann[i][j] = false;
						if (k == 2)
							p1count++;
					}
				}
			}
			result[h] = p1count * p1 + p2count * p2;
			arr[0][0] = 0; arr[0][1] = 1;
			arr[1][0] = 1; arr[1][1] = 0;
		}

		cout << min(result[0], result[1]) << endl;
	}
	return 0;
}