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
	int v, e;
	cin >> v >> e;

	vector<pair<int,int> >order(v + 1);
	vector<int> locations(v + 1);
	int tmp;
	locations[0] = INF;
	order[0] = make_pair(locations[0], 0);
	for (int i = 1; i < v + 1; i++){
		cin >> tmp;
		locations[i] = tmp;
		order[i] = make_pair(tmp, i);
	}

	sort(order.begin(), order.end());

	vector<vector<int> > graph(v + 1, vector<int>(v + 1, INF));
	vector<vector<int> > floydgraph(v + 1, vector<int>(v + 1, INF));
	int a, b, c;
	for (int i = 0; i < e; i++){
		cin >> a >> b >> c;
		graph[a][b] = c;
		graph[b][a] = c;
	}

	for (int i = 1; i < v + 1; i++){
		for (int j = 1; j < v + 1; j++){
			if (i == j)
				floydgraph[i][j] = 0;
			else
				floydgraph[i][j] = graph[i][j];
		}
	}

	for (int k = 0; k < v; k++){
		int delaypos = order[k].second;
		for (int i = 1; i < v + 1; i++){
			for (int j = 1; j < v + 1; j++){
				graph[i][j] = min(graph[i][j], graph[i][delaypos] + graph[delaypos][j]);
				floydgraph[i][j] = min(floydgraph[i][j], graph[i][delaypos] + graph[delaypos][j] + locations[delaypos]);
			}
		}
	}

	int tc;
	cin >> tc;
	while (tc--){
		int s, f;
		cin >> s >> f;
		cout << floydgraph[s][f] << endl;


	}
	return 0;
}