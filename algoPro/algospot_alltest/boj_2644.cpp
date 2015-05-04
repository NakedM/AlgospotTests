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
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	int m;
	cin >> m;
	vector<vector<int> > family(n + 1);
	for (int i = 0; i < m; i++){
		int t1, t2;
		cin >> t1 >> t2;
		family[t1].push_back(t2);
		family[t2].push_back(t1);
	}

	vector<int> chk(n + 1, INF);
	queue<int> que;
	que.push(a);
	chk[a] = 0;

	while (!que.empty()){
		int here = que.front();
		que.pop();
		for (int i = 0; i < family[here].size(); i++){
			int there = family[here][i];
			if (chk[there] > chk[here] + 1){
				que.push(there);
				chk[there] = chk[here] + 1;
			}
		}
	}

	if (chk[b] == INF)
		cout << -1 << endl;
	else
		cout << chk[b] << endl;

	return 0;
}