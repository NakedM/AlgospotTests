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
const int inf = 987654321;
vector<bool> visit;
int N;

bool dfs(int here, int jump){
	visit[here] = true;
	if (here == 1)
		return true;

	for (int i = 0; i < N; i++){
		if(!visit[i] && graph[here][i] <= jump)
			return dfs(i,jump);
	}

	return false;
}

int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;

	while (tc--){
		graph.clear();
		visit.clear();
		vector<pair<int, int> > points;

		int jump;
		cin >> jump;		
		jump *= jump;

		int sx, sy, fx, fy; //0 1
		cin >> sx >> sy >> fx >> fy;
		
		points.push_back(make_pair(sx, sy));
		points.push_back(make_pair(fx, fy));

		int n;
		cin >> n;
		int a, b;
		for (int i = 0; i < n; i++){
			cin >> a >> b;
			points.push_back(make_pair(a, b));
		}
		N = n+ 2;
		graph = vector<vector<int> >(N, vector<int>(N, inf));
		visit = vector<bool>(N, false);
		for (int i = 0; i < N; i++){
			for (int j = i+1; j < N; j++){
				if (i != j){
					int x = points[i].first - points[j].first;
					int y = points[i].second - points[j].second;
					int dist = x*x + y*y;					
					graph[i][j] = dist;
					graph[j][i] = dist;

				}
			}
		}


		/*for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				cout << graph[i][j] << " ";
			}
			cout << endl;
		}*/
		bool flg = false;
		//flg = dfs(0, jump);


		queue<int> que;
		que.push(0);
		vector<int> cost(N, 0);
		cost[0] = 0;
		while (!que.empty()){
			int here = que.front();
			que.pop();
			int c = cost[here];
			for (int i = 0; i < N; i++){
				if (cost[i] == 0 && graph[here][i] <= jump){
					que.push(i);
					cost[i] = c + 1;
				}
			}
		}

		
		
		if (cost[1] > 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;


		///// dfs로는 안되고 bfs로는 ac 받음 왜일까???

	}
	return 0;
}