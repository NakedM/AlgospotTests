#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits>
#include<bitset>
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
		int lim;
		cin >> lim;
		
		int sum = 0;
		int t;
		for (int i = 0; i < 9; i++){
			cin >> t;
			sum += t;

		}
		
		if (sum <= lim)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}