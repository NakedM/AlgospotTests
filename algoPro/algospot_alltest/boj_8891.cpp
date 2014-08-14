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
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	vector<int> order;
	order.push_back(0);
	for (int i = 1;i<300; i++){
		int v = order[i - 1] + i;
		order.push_back(v);
		
	}
	while (tc--){
		int a, b;
		cin >> a >> b;
		vector<int>::iterator it, it2;
		it = lower_bound(order.begin(), order.end(), a);
		it2 = lower_bound(order.begin(), order.end(), b);

		int xa = it - order.begin();
		int xb = it2 - order.begin();
		
		int dista = order[xa] - a;
		int distb = order[xb] - b;
		
		int x1 = xa - dista;
		int x2 = xb - distb;
		int y1 = 1 + dista;
		int y2 = 1 + distb;

		int nx = x1 + x2;
		int ny = y1 + y2;
		
		int s = nx + ny -1;
		
		cout << order[s] - (s - nx)<< endl;



	}
	return 0;
}