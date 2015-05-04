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
	vector<bool> nums(10001, true);
	vector<string> primes;

	for (int i = 2; i < 5001; i++){
		if (nums[i]){
			for (int j = i+i; j < 10001; j += i)
				nums[j] = false;
		}
	}

	for (int i = 1000; i < 10000; i++){
		if (nums[i])
			primes.push_back(to_string(i));
	}

	int sz = primes.size();
	vector<vector<int> > graph(sz);
	for (int i = 0; i < sz; i++){
		for (int j = i + 1; j < sz; j++){
			int c = 0;
			for (int h = 0; h < 4; h++){
				if (primes[i][h] != primes[j][h])
					c++;
			}
			if (c == 1){
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	int tc;
	cin >> tc;
	while (tc--){
		string str1, str2;
		cin >> str1 >> str2;
		int a = find(primes.begin(), primes.end(), str1) - primes.begin();
		int b = find(primes.begin(), primes.end(), str2) - primes.begin();

		vector<int> chk(sz, INF);
		queue<int> que;
		que.push(a);
		chk[a] = 0;

		while (!que.empty()){
			int here = que.front();
			que.pop();

			int tsz = graph[here].size();
			for (int i = 0; i < tsz; i++){
				int there = graph[here][i];
				if (chk[there] > chk[here] + 1)
				{
					chk[there] = chk[here] + 1;
					que.push(there);
				}
			}
		}
		cout << chk[b] << endl;

	}
	return 0;
}