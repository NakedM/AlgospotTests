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
	int n, m;
	cin >> n >> m;

	vector<int> pack;
	vector<int> single;
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		pack.push_back(a);
		single.push_back(b);
	}
	int v = n / 6;
	int r = n % 6;

	

	vector<int> result;
	
	
	for (int i = 0; i < m; i++){
		int res = 0;
		int res2 = 0;
		int res3 = 0;
		res += v*pack[i];
		res += r*single[i];
		res2 += (v + 1)*pack[i];
		res3 += n*single[i];
		res = min(res, res2);
		res = min(res, res3);
		result.push_back(res);
	}
	sort(pack.begin(), pack.end());
	sort(single.begin(), single.end());

	int rs = 0;
	rs += v*pack[0];
	rs += r*single[0];
	result.push_back(rs);

	sort(result.begin(), result.end());


	cout << result[0] << endl;

	return 0;
}