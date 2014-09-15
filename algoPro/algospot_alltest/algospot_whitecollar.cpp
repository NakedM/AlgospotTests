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
#include<set>
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
		int n, m;
		cin >> n >> m;

		vector<vector<int> > graph(n + 1);

		for (int i = 0; i < m; i++){
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
		}


		queue<int> que;
		vector<int> cost(n + 1, 987654321);
		vector<vector<int> > past(n + 1);
		que.push(1);
		cost[1] = 0;

		while (!que.empty()){
			int here = que.front();
			int c = cost[here];
			que.pop();
			int sz = graph[here].size();

			for (int i = 0; i < sz; i++){
				if (cost[graph[here][i]] > c+1){
					que.push(graph[here][i]);
					cost[graph[here][i]] = c + 1;
					past[graph[here][i]].clear();
					past[graph[here][i]].push_back(here);
				}
				else if (cost[graph[here][i]] == c + 1){
					past[graph[here][i]].push_back(here);
				}
			}
		}

		graph.clear();
		vector<bool> visit(n + 1, false);			
		//queue<int> qq;
		visit[n] = true;
		que.push(n);

		while (!que.empty()){
			int here = que.front();
			que.pop();
			int sz = past[here].size();

			for (int i = 0; i < sz; i++){
				que.push(past[here][i]);
				visit[past[here][i]] = true;
			}
		}

		for (int i = 1; i < n + 1; i++){
			if (visit[i])
			{
				cout << i;
				if (i != n)
					cout << " ";
				else
					cout << endl;
			}
		}
		//sort(result.begin(), result.end());	
		//int sszz = result.size();
		/*int i = 0;
		for (set<int>::iterator it = result.begin(); it != result.end(); ++it,++i){
			cout<< *it;
			if (i != sszz - 1)
				cout << " ";
			else
				cout << endl;
		}*/


	}
	return 0;
}