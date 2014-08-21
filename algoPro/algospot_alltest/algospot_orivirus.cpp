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
		vector<vector<int> > graph(n, vector<int>(n, 0));

		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cin >> graph[i][j];
			}
		}

		
		

		int m;
		cin >> m;
		vector<int> result(m, 2);
		for (int i = 0; i < m; i++){
			vector<bool> infe(n, false);
			vector<int> aroundVir(n, 0);
			int a, b;
			cin >> a >> b;
			queue<int> que;
			que.push(a-1); infe[a-1] = true;
			que.push(b-1); infe[b-1] = true;

			while (!que.empty()){
				int cur = que.front();
				que.pop();

				for (int fr = 0; fr < n; fr++){
					if (graph[cur][fr]){
						aroundVir[fr]++;
						if (aroundVir[fr] >= 2 && !infe[fr]){
							que.push(fr);
							infe[fr] = true;
							result[i]++;
						}
					}
				}
			}
		}

		for (int i = 0; i < m; i++){
			cout << result[i];
			if (i != m - 1)
				cout << " ";
			else
				cout << endl;
		}

	}
	return 0;
}