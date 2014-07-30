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

vector<vector<pair<int, int> > > graph;
const int INF = 987654321;
vector<vector<bool> > cango;
int V, w;

vector<bool> visit;

void dfs(int s, int here){
	visit[here] = true;
	for (int i = 0; i < graph[here].size(); i++){
		if (!visit[graph[here][i].first]){
			cango[s][graph[here][i].first] = true;
			dfs(s, graph[here][i].first);
		}
	}
}


//음수 사이클이 있을 경우 텅 빈 배열을 반환
int bellmanFord(int src, int andro){
	vector<int> upper(V, INF);
	upper[src] = 0;
	
	for (int iter = 0; iter < V-1; iter++){		
		for (int here = 0; here < V; here++){
			for (int i = 0; i < graph[here].size(); i++){
				int there = graph[here][i].first;
				int cost = graph[here][i].second;
				if (upper[there] > upper[here] + cost){
					upper[there] = upper[here] + cost;				
				}
			}			
		}		
	}
	//V번째에서 완화가 된다면 사이클이 있다는것
	//이것이 V번째
	for (int here = 0; here < V; here++){
		for (int i = 0; i < graph[here].size(); i++){
			int there = graph[here][i].first;
			int cost = graph[here][i].second;
			if (upper[there] > upper[here] + cost){
				if (cango[src][here] && cango[here][andro])
					return -INF;			
			}

		}
	}
	return upper[andro];
}

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		cin >> V >> w;
		
		graph = vector<vector<pair<int, int> > >(V);
		cango = vector<vector<bool> >(V, vector<bool>(V, false));
		int a, b, c;
		for (int i = 0; i < w; i++)
		{
			cin >> a >> b >> c;
			graph[a].push_back(make_pair(b, c));			
		}
		
		
		for (int i = 0; i < V; i++){
			visit = vector<bool>(V, false);
			cango[i][i] = true;
			dfs(i, i);
		}
		
		int result = bellmanFord(0, 1);
		if (!cango[0][1]){
			cout << "UNREACHABLE" << endl;
			continue;
		}

		if (result == INF || result == -INF){
			cout << "INFINITY" << " ";
		}
		else {
			cout << result << " ";
		}

		for (int i = 0; i < V; i++){
			for (int j = 0; j < graph[i].size();j++){
				graph[i][j].second = -graph[i][j].second;
			}
		}
		result = bellmanFord(0, 1);

		if (result == INF || result == -INF){
			cout << "INFINITY" << endl;
		}
		else {
			cout << -result << endl;
		}
	}
	return 0;
}