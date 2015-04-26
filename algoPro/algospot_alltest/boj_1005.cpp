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

const int INF = 987654321;

#pragma warning (disable:4996)
ifstream in("input.txt");



int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		int n, k;
		cin >> n >> k;
		vector<int> times(n + 1);
		vector<vector<int> > graph(n + 1);
		int w;		

		for (int i = 1; i<n+1; ++i)
			cin>>times[i];

		for (int i = 0; i < k; ++i){
			int a, b;
			cin >> a >> b;
			graph[b].push_back(a);
		}
		cin >> w;

		queue<int> que;
		vector<int> building(n + 1, 0);
		que.push(w);
		building[w] = times[w];

		while (!que.empty()){
			int here = que.front();
			que.pop();
			
			int sz = graph[here].size();
			for (int i = 0; i < sz; ++i){
				int there = graph[here][i];
				if (building[there] < building[here] + times[there]){
					que.push(there);
					building[there] = building[here] + times[there];
				}
			}
		}		
		cout << building[max_element(building.begin(), building.end())-building.begin()] << endl;

		
	}
	return 0;
}