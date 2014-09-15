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

//이분 그래프 이분 매칭 공부하고 다시 풀기

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
		int n, m, p1, p2;
		cin >> n >> m >> p1 >> p2;

		vector<vector<bool> > graph(n+1, vector<bool>(m+1, false));

		int blenkcount = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				char c;
				cin >> c;
				if (c == '0')
					graph[i][j] = true;
				else
					graph[i][j] = false;
				if (graph[i][j])
					blenkcount++;
			}
		}

		if (p1*2 <= p2){
			cout << blenkcount *  p1 << endl;
			continue;
		}

		
	}
	return 0;
}