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

	vector<vector<long long> > vc(65, vector<long long>(11, 0));
	for (int i = 0; i < 10; i++)
		vc[1][i] = 1;
	for (int i = 2; i < 65; i++){
		for (int j = 9; j >= 0; j--){
			vc[i][j] = vc[i - 1][j] + vc[i][j + 1];
		}
	}
	while (tc--){
		int n;
		cin >> n;

		long long sum = 0;
		for (int i = 0; i < 10; i++)
			sum += vc[n][i];

		cout << sum << endl;
	}
	return 0;
}