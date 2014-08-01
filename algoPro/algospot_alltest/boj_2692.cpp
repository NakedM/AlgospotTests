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

vector<double> x(3);
vector<double> y(3);

vector<double> equalizer(int a, int b, int c){
	vector < double > result;

	double midx = (x[a] + x[b]) / 2;
	double midy = (y[a] + y[b]) / 2;

	double distx = x[c] - midx;
	double disty = y[c] - midy;


	double A, B, C;
	if (distx == 0.0){
		A = 1.0;
		B = 0.0;
		C = midx;
	}
	else {
		double alpa = disty / distx;
		double tmpC = y[c] - x[c] * alpa;

		double t = 1.0 / (1.0 + (alpa*alpa));
		t = sqrt(t);
		B = t;
		A = -(alpa / B);
		C = tmpC / B;
	}

	result.push_back(A);
	result.push_back(B);
	result.push_back(C);
	result.push_back(A*A + B*B);


	return result;
}

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		

		double a, b;
		for (int i = 0; i < 3; i++){
			cin >> a >> b;
			x[i] = a;
			y[i] = b;
		}
		
		vector<vector<double>> result;
		result.push_back(equalizer(0, 2, 1));
		result.push_back(equalizer(0, 1, 2));
		result.push_back(equalizer(1, 2, 0));

		cout << fixed;
		cout.precision(5);
		for(int i=0;i<3;i++)
			cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << " "<< result[i][3]<< endl;
	}
	return 0;
}