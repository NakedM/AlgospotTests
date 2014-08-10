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

		vector<int> vc(10, -1);
		int rep = 1;
		int t = a % 10;
		vc[t] = 1;		
		for (int i = 2; i <= b; i++){
			t *= a;
			t %= 10;
			if (vc[t] != -1)
				break;
			vc[t] = i;
			rep = i;
		}

		int r = (b-1) % rep;
		r++;
		for (int i = 0; i < 10; i++){
			if (vc[i] == r){
				if (i == 0)
					cout << 10 << endl;
				else
					cout << i << endl;
			}
		}
	}
	return 0;
}