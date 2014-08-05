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

const int MOD = 1000000007;


int gcd(int p, int q){
	return q == 0 ? p : gcd(q, p % q);
}

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif

	
	
	int tc;
	cin >> tc;	
	while (tc--){
		
		int n, m;
		cin >> n >> m;
		vector<vector<int> >vc(n+1);

		for (int i = 1; i <= n; i++){
			for (int j = 0; j <= i; j++){
				vc[i].push_back(0);
			}
		}

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				int res = gcd(i, j);
				vc[i][res]++;
			}
		}

		vector<int> sums(n + 1, 0);
		int result = 0;
		
		for (int i = 1; i <= n; i++){
			for (int j = i; j <= n; j++){
				sums[i] += vc[j][i];
			}
		}
		
		

		for (int i = 1; i <= n; i++)
			result += (sums[i]*i)%MOD;
		cout << result << endl;

	}
	return 0;
}