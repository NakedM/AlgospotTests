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
		int a, b;
		cin >> a >> b;

		if (a == b)
			cout << 4 << endl;
		else if (a > b)
			cout << 0 << endl;
		else {
			int dist = b - a;
			cout << 4 + dist << endl;

		}
	}
	return 0;
}