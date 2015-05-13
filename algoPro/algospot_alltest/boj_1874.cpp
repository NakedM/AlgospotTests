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
	int n;
	cin >> n;
	vector<int> vc(n);
	for (int i = 0; i < n; i++)
		cin >> vc[i];

	int m = vc[0];
	int c = vc[0];
	bool bl = true;
	for (int i = 1;i < n; i++){
		if (vc[i] > m)
			m = vc[i];
		else if (vc[i] > c)
		{
			bl = false;
			break;
		}
		c = vc[i];
	}
	if (!bl)
	{
		cout << "NO" << endl;
		return 0;
	}

	m = 0;
	for (int i = 0; i < n; i++){
		if (vc[i] > m){
			for (int j = 0; j < vc[i] - m; j++)
				cout << "+" << endl;
			m = vc[i];
			cout << "-" << endl;
		}
		else
			cout << "-" << endl;

	}

	return 0;
}