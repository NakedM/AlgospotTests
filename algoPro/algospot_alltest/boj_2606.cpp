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

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
		int v, e;
		cin >> v >> e;
		
		vector<vector<bool>> graph(v+1, vector<bool>(v+1, false));
		for (int i = 0; i < e; i++){
			int a, b;
			cin >> a >> b;
			graph[a][b] = true;
			graph[b][a] = true;
		}

		for (int i = 1; i <= v; i++) graph[i][i] = true;

		for (int k = 1; k <= v; k++){
			for (int i = 1; i <= v; i++){
				for (int j = 1; j <= v; j++)
					graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]); 
			}
		}

		int count = 0;
		for(int i=2;i<=v;i++)
		if (graph[1][i])
			count++;

		cout << count << endl;
	
	return 0;
}