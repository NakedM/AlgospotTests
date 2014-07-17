#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<iterator>
using namespace std;

ifstream in("input.txt");

int main(){
#ifdef _CONSOLE    
	freopen("input.txt", "r", stdin);
#endif
	int tc;
	cin>>tc;
	while(tc--){
		int n;
		cin>>n;
		
		vector<pair<double, double> > point(n,make_pair(0.0,0.0));

		double t1, t2;
		for (int i = 0; i < n; i++)
		{
			cin >> t1 >> t2;
			point[i] = make_pair(t1, t2);
		}

		vector<vector<double> > vc;
		vector<double> tmp(n, 10000000.0);
		for (int i = 0; i < n; i++)
			vc.push_back(tmp);

		
		vector<double> eachmins;
		for (int i = 0; i < n; i++){
			double minn = 10000000.0;
			for (int j = i+1; j < n; j++)
			{
				double x = point[i].first - point[j].first;
				double y = point[i].second - point[j].second;
				double dis = x*x + y*y;

				vc[i][j] = dis;
				vc[j][i] = dis;
			}
			for (int j = 0; j < n; j++)
			{
				if (vc[i][j] < minn)
					minn = vc[i][j];
			}
			eachmins.push_back(minn);
		}

		vector<double>::iterator it;
		it = max_element(eachmins.begin(), eachmins.end());
		double result = *it;

		cout.precision(2);
		cout << fixed;
		cout << sqrt(result) << endl;

	}
	return 0;
}