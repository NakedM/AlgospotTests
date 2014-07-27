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

ifstream in("input.txt");

vector<int> order;
vector<bool> visit;
vector<vector<bool>> graph;
void dfs(int here){
	visit[here] = true;
	for (int there = 0; there < 26; there++){
		if (graph[here][there] && !visit[there])
			dfs(there);
	}
	order.push_back(here);
}




int main(){
#ifdef _HONG   
	freopen("input.txt", "r", stdin);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		int n;
		cin >> n;
		string str;
		vector<string> words;
		for (int i = 0; i < n; i++){
			cin >> str;
			words.push_back(str);
		}
		graph = vector<vector<bool> >(26, vector<bool>(26, false));

		int wsz = words.size();
		for (int i = 1; i < wsz; i++){
			int minlen = min(words[i].size(), words[i - 1].size());

			for (int k = 0; k < minlen; k++){
				if (words[i - 1][k] != words[i][k]){					
					int y = words[i][k] - 'a';
					int x = words[i - 1][k] - 'a';
					graph[y][x] = true; // y는 x보다 뒤이다.
					break;
				}
			}
		}
		visit = vector<bool>(26, false);
		order.clear();

		for (int i = 0; i < 26; i++){
			if (!visit[i])
				dfs(i);
		}
		//reverse(order.begin(), order.end());

		bool flg = true;

		for (int i = 0; i < 26; i++){
			for (int j = i + 1; j < 26; j++){
				if (graph[order[i]][order[j]])
					flg = false;
			}
		}

		if (flg)
		{
			for (int i = 0; i < 26; i++){
				char t = order[i] + 'a';
				cout << t;
			}
			cout << endl;
		}
		else
			cout << "INVALID HYPOTHESIS" << endl;



	}
	return 0;
}