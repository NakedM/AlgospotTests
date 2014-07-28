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

vector<vector<bool> > graph;
vector<int> visited;
enum{ unwatch = 0, watch = 1, install };
int cameras;
int g, h;

int dfs(int here){
	visited[here] = true;
	vector<int> children(3, 0);
	for (int there = 0; there < g; there++){
		if (graph[here][there] == 1 && !visited[there]){
			++children[ dfs(there)];			
		}
	}

	if (children[unwatch]){
		cameras += 1;
		return install;
	}
	
	if (children[install])
		return watch;
	return unwatch;	
}

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		//int g, h
		cin >> g >> h;
		graph = vector<vector<bool> >(g, vector<bool>(g, false));

		int a, b;
		for (int i = 0; i < h; i++){
			cin >> a >> b;
			graph[a][b] = true;
			graph[b][a] = true;
		}
		visited = vector<int>(g, 0);
		cameras = 0;

		
		for (int i = 0; i < g; i++){
			if (!visited[i] && dfs(i) == unwatch)1
				cameras++;
		}

		cout << cameras << endl;

	}
	return 0;
}