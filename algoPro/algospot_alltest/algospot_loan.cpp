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

double payMonthly(double n, int m, double p, double payment){

	double balance = n;

	for (int i = 0; i < m; i++){
		balance *= (1.0 + (p / 12.0) / 100);

		balance -= payment;

	}

	return balance;
}

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		double n, p;
		int m;
		cin >> n >> m >> p;

		//ÀÌºÐ¹ý
		double low = 0;
		double high = n*(1.0 + (p / 12.0) / 100);
		
		for (int i = 0; i < 100; i++){
			double mid = (low + high) / 2.0;
			double ret = payMonthly(n, m, p, mid);

			if ( ret <= 0.0)
				high = mid;
			else
				low = mid;
		}

		cout.precision(10);
		cout << fixed;
		cout << high << endl;


	}
	return 0;
}