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

vector<vector<int> > graph;
vector<bool> visit;
vector<int> order;
void dfs(int here){
	int gsz = graph[here].size();
	for (int there = 0; there < gsz; there++)
	{
		if (!visit[graph[here][there]]){
			visit[graph[here][there]] = true;
			
			dfs(there);
		}
	}
	order.push_back(here);
}


/////////// 다 구현못함.. 다시 구현해야할듯

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		int n;
		vector<string> words(n);
		string str;
		
		for (int i = 0; i < n; i++){
			cin >> str;
			words[i] = str;
		}

		graph = vector<vector<int> >(26);
		vector<pair<int, int>> chars(n);

		for (int i = 0; i < n; i++){
			int f = words[i][0] - 'a';
			int s = words[i][words[i].length() - 1] - 'a';

			chars[i] = make_pair(f, s);
			graph[f].push_back(i);
		}
		
		for (int i = 0; i < 26; i++){
			order.clear();
			visit = vector<bool>(n, false);
			bool flg = true;

			dfs(i);
			for (int j = 0; j < n; j++){
				if (!visit[j]){
					flg = false;
					break;
				}
			}
			if (flg){
				break;
			}
		}
	}
	return 0;
}