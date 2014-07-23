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

const int INF = 123456789;
vector<vector<int> > positions;
vector<int> countEdge;
vector<vector<int> > graph;

int bfs(int start,int n ){
	vector<int> val(n, INF);
	queue<int> que;

	val[start] = 0;
	que.push(start);

	while (!que.empty()){
		int here = que.front();
		que.pop();

		int sz = graph[here].size();
		for (int there = 0; there < sz; there++){
			if (val[here] + 1 < val[graph[here][there]]){
				val[graph[here][there]] = val[here] + 1;
				que.push(graph[here][there]);
			}
		}
	}
	
	int maxx = 0;
	for (int i = 0; i<n; i++)
	{
		if (val[i] > maxx)
			maxx = val[i];
	}
	return maxx;
}

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		int n;
		cin >> n;
		int a, b, c;
		
		positions = vector<vector<int> >();
		countEdge = vector<int>(n,0);
		graph = vector<vector<int> >(n);
		vector<pair<int, int> > orderDis;
		vector<int> wall(5);// xh, xl, yh, yl, wall;
		

		enum{ xh = 0, xl, yh, yl, dis };

		for (int i = 0; i < n; i++)
		{
			cin >> a >> b >> c;
			wall[xh] = a + c;
			wall[xl] = a - c;
			wall[yh] = b + c;
			wall[yl] = b - c;
			wall[dis] = c;
			positions.push_back(wall);
			orderDis.push_back(make_pair(c, i));
		}

		sort(orderDis.begin(), orderDis.end());

		for (int i = 0; i < n; i++){
			int smaller = orderDis[i].second;
			for (int j = i + 1; j < n; j++){
				int bigger = orderDis[j].second;
				if (positions[smaller][xh] < positions[bigger][xh] &&
					positions[smaller][xl] > positions[bigger][xl] &&
					positions[smaller][yh] < positions[bigger][yh] &&
					positions[smaller][yl] > positions[bigger][yl]){
					
					graph[smaller].push_back(bigger);
					graph[bigger].push_back(smaller);
					
					countEdge[smaller] += 1;
					countEdge[bigger] += 1;
					break;
				}
			}
		}

		vector<int> oneEdges; //최대길이는 어느 한쪽이든 하나는 잎
		for (int i = 0; i < n; i++)
		{
			if (countEdge[i] == 1)
				oneEdges.push_back(i);
		}

		int sz = oneEdges.size();
		int maxx = 0;

		for (int i = 0; i<sz; i++){
			int res = bfs(oneEdges[i],n);
				if (maxx < res)
					maxx = res;
		}
		cout << maxx << endl;

		positions.clear();
		countEdge.clear();
		graph.clear();
	}
	return 0;
}