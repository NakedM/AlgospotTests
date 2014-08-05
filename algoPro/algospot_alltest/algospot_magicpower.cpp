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
	int tc;
	cin >> tc;
	while (tc--){
		int n, m;
		cin >> n >> m;
		
		priority_queue<int> items;
		for (int i = 0; i < n; i++){
			int t;
			cin >> t;
			items.push(t);
		}
		int maxx;
		int sum = 0;

		for (int i = 0; i < m; i++){
			if (items.empty())
				break;
			maxx = items.top();
			sum += maxx;
			items.pop();
			maxx -= 1;
			if (maxx != 0)
				items.push(maxx);
		}
		cout << sum << endl;

	}
	return 0;
}