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

////////////////////// 유클리드 알고리즘 (최대공약수)

int gcd(int p, int q){
	return q == 0 ? p : gcd(q, p % q);
}


////////////////////// a / b 보다 큰 최소 정수

int ceiling(int a, int b){
	return (a + b - 1) / b;
}

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		int n;
		cin >> n;
		vector<int> original(n);
		vector<int> alreadyput(n);

		for (int i = 0; i < n; i++)
			cin >> original[i];
		for (int i = 0; i < n; i++)
			cin >> alreadyput[i];

		int greatcd = original[0];

		for (int i = 1; i < n; i++)
			greatcd = gcd(greatcd, original[1]);

		int more = greatcd;

		for (int i = 0; i < n; i++)
			more = max(more, ceiling(alreadyput[i] * greatcd, original[i]));


		vector<int> result(n);
		for (int i = 0; i < n; i++){
			result[i] = ((original[i] * more) / greatcd) - alreadyput[i];
		}
		for (int i = 0; i < n; i++){
			cout << result[i];
			if (i != n - 1)
				cout << " ";
			else
				cout << endl;
		}


	}
	return 0;
}