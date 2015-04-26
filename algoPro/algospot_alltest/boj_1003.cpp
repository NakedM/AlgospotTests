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

	vector<int> zero(41);
	vector<int> one(41);
	zero[0] = 1;
	one[0] = 0;
	zero[1] = 0;
	one[1] = 1;
	for (int i = 2; i<41; i++){
		zero[i] = zero[i - 1] + zero[i - 2];
		one[i] = one[i - 1] + one[i - 2];
	}

	int tc;
	cin >> tc;
	while (tc--){
		int n;
		cin >> n;
		cout << zero[n] << " " << one[n] << endl;
	}
	return 0;
}