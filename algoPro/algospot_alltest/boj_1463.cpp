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

	int n;
	cin >> n;

	vector<int> vc(1000010, INF);
	vc[1] = 0;
	vc[2] = vc[3] = 1;

	for (int i = 4; i < n + 1; i++){
		int one = 0,two = 0,three = 0;
		if (i % 3 == 0)
			one = i / 3;
		if (!(i & 1))
			two = i / 2;
		three = i - 1;

		vc[i] = min(min(vc[one], vc[two]), vc[three])+1;
	}
	cout << vc[n] << endl;

	return 0;
}