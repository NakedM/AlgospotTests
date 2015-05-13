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

vector<vector<int> > graph;
int xx[4] = { 0, 1, 0, -1 };
int yy[4] = { -1, 0, 1, 0 };

void dfs(int cy, int cx){
	graph[cy][cx] = 0;
	for (int i = 0; i < 4; i++){
		if (graph[cy + yy[i]][cx + xx[i]] == 1)
			dfs(cy + yy[i], cx + xx[i]);
	}
	return;
}

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		int m, n, k;
		cin >> m >> n >> k;
		graph = vector<vector<int> >(m+5, vector<int>(n+5, 0));

		for (int i = 0; i < k; i++){
			int a, b;
			cin >> a >> b;
			graph[a+1][b+1] = 1;
		}

		int count = 0;
		for (int i = 1; i < m + 1; i++){
			for (int j = 1; j < n + 1; j++){
				if (graph[i][j] == 1){
					count++;
					dfs(i, j);
				}
			}
		}
		
		cout << count << endl;
	}
	return 0;
}