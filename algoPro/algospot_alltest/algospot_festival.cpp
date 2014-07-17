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

#pragma warning (disable:4996)
using namespace std;

ifstream in("input.txt");


int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	
#endif
	int tc;
	cin >> tc;
	while (tc--){
		int n, m;
		cin >> n >> m;
		vector<int> vc(n, 0);

		for (int i = 0; i < n; i++)
			cin >> vc[i];

		vector<double> tmp(n, 0.0);
		vector<vector<double> > pann;

		for (int i = 0; i < n; i++)
		{
			pann.push_back(tmp);
		}
		
		for (int i = 0; i < n; i++)
			pann[0][i] = double(vc[i]);

		double minn = 123456789.0;


		for (int i = 1; i < n; i++)
		{
			for (int j = m + i - 1; j <= n; j++)
			{
				double psum = 0.0;
				for (int k = j - (m + i -1); k < j; k++){
					psum += pann[0][k];
				}
				pann[i][j-1] = psum /  (m + i - 1);
				if (pann[i][j-1] < minn)
					minn = pann[i][j-1];
			}
		}

		if (m == 1)
		{
			for (int i = 0; i < n; i++)
			{
				if (pann[0][i] < minn)
					minn = pann[0][i];
			}
		}

		cout.precision(11);
		cout << fixed;
		cout << minn << endl;

		vc.clear();
		pann.clear();


	}
	return 0;
}