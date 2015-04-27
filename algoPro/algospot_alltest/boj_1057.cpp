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
	int n, a, b;
	int count = 0;
	cin >> n >> a >> b;

	while (a != b)
	{
		if (a & 1 != 0)
			a = (a / 2) + 1;
		else
			a /= 2;

		if (b & 1 != 0)
			b = (b / 2) + 1;
		else
			b /= 2;

		count++;	
	}

	cout << count << endl;
	return 0;
}