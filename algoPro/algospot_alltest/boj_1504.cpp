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

int V;
vector<vector<pair<int, int> > > adj;

int dijkstra(int src,int destination){
	vector<int> dist(V+1, 987654321);
	dist[src] = 0;
	priority_queue<pair<int, int> > pq; //max가 top에 감 그래서 그래프에 가중치를 전부 -로 둠
	//아니면
	//pritority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	pq.push(make_pair(0, src));
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;

		pq.pop();

		if (dist[here] < cost) continue;

		for (int i = 0; i<adj[here].size(); i++){
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;

			if (dist[there] > nextDist){
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist[destination];
}

int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int v, e;
	cin >> v >> e;
	V = v;
	adj = vector<vector<pair<int, int> > >(v + 1);

	for (int i = 0; i < e; i++){
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b,c));
		adj[b].push_back(make_pair(a,c));
	}

	int mid1, mid2;
	cin >> mid1 >> mid2;

	int middist = dijkstra(mid1, mid2);

	int r1 = middist + dijkstra(1, mid1) + dijkstra(mid2, v);
	int r2 = middist + dijkstra(1, mid2) + dijkstra(mid1, v);

	cout << min(r1, r2) << endl;
	


	return 0;
}