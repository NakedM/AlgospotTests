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

const int INF = 987654321;

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		int v, e, n;
		cin >> v >> e >> n;
		vector<vector<int> > graph(v, vector<int>(v, INF));

		int a, b, c;
		for (int i = 0; i < e; i++){
			cin >> a >> b >> c;
			graph[a][b] = c;
			graph[b][a] = c;
		}

		for (int i = 0; i < v; i++) graph[i][i] = 0;

		for (int k = 0; k < v; k++){
			for (int i = 0; i < v; i++){
				if (graph[i][k] != INF) { //이건 최적화 할때
					for (int j = 0; j < v; j++){
						graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
					}
				}
			}
		}

		int count = 0;
		for (int h = 0; h < n; h++){
			cin >> a >> b >> c;
			if (c >= graph[a][b])
				count++;
			else{
				graph[a][b] = c;
				graph[b][a] = c;				
					for (int i = 0; i < v; i++){						
							for (int j = 0; j < v; j++){
								graph[i][j] = min(graph[i][j], min(graph[i][a] +graph[a][b]+ graph[b][j],
									graph[i][b] + graph[b][a] + graph[a][j]));
							}
						
					}						
			}
		}
		cout << count << endl;
	}

	return 0;
}