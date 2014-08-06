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
		int n, k;
		cin >> n >> k;

		int amount = 1;
		int c = 0;
		for (int i = 1; i <= n; i++){
			amount = i*k;
			amount %= 100000;
			if (amount >= 10000 && amount < 11112){
				c = i;
				break;
			}
			//if (amount >= 11112)
			//	break;
		}
		double t;
		int res;
		if (c == 0){
			t = n*k - n*k* 0.1;
			res = int(t);
		}
		else{
			int v = n / c;
			int r = n % c;
			int p = k / 10000;
			p *= 10000;
			res = v * c * p;
			t = r*k - r*k * 0.1;
			res = res + int(t);
			//cout << res << " ";
		}
		cout << res << endl;
	}
	return 0;
}