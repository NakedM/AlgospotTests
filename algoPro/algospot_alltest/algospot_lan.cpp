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

/////////union fine set 유니온 파인드
struct DisjointSet {
	vector<int> parent, rank;
	DisjointSet(int n) : parent(n), rank(n, 1){
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int u){
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v){
		u = find(u);
		v = find(v);

		if (u == v) return;
		if (rank[u] > rank[v]) swap(u, v);

		parent[u] = v;
		if (rank[u] == rank[v]) ++rank[v];
	}
};

///////////크루스칼 알고리즘 kruskal's algorhtm

int V;
vector<vector<double> > graph;

double kruskal(vector<pair<int, int> >& selected){
	double ret = 0;
	selected.clear();

	vector<pair<double, pair<int, int> > > edges;
	for (int u = 0; u < V; u++){
		for (int v = 0; v < V; v++){
			if (u != v){
				double cost = graph[u][v];
				edges.push_back(make_pair(cost, make_pair(u, v)));
			}
		}
	}


	sort(edges.begin(), edges.end());

	DisjointSet sets(V);
	for (int i = 0; i < edges.size(); i++){
		double cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;

		if (sets.find(u) == sets.find(v)) continue;

		sets.merge(u, v);
		selected.push_back(make_pair(u, v));
		ret += cost;
	}
	return ret;
}

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		int n, m;
		cin >> n >> m;
		V = n;
		vector<int> posx(n);
		vector<int> posy(n);
		for (int i = 0; i < n; i++)
			cin >> posx[i];
		for (int i = 0; i < n; i++)
			cin >> posy[i];

		graph = vector<vector<double> >(n, vector<double>(n, 0.0));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (i != j){
					int x = posx[i] - posx[j];
					int y = posy[i] - posy[j];
					int dist = x*x + y*y;
					double d = sqrt(double(dist));

					graph[i][j] = d;
					graph[j][i] = d;
				}
			}
		}

		int a, b;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			graph[a][b] = 0.0;
			graph[b][a] = 0.0;
		}

		vector<pair<int, int> > sel;
		double res = kruskal(sel);
		cout << fixed;
		cout.precision(10);
		cout << res << endl;

	}
	return 0;
}