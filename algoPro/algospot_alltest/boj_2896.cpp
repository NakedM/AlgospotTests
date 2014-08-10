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
	vector<int> amount(3);
	cin >> amount[0] >> amount[1] >> amount[2];
	vector<int> bal(3);
	cin >> bal[0] >> bal[1] >> bal[2];
	
	vector<double> k(3);

	for (int i = 0; i < 3; i++)
		k[i] = double(amount[i]) / double(bal[i]);

	double d = *min_element(k.begin(), k.end());
	cout << fixed;
	cout.precision(5);
	cout << amount[0] - bal[0] * d << " "
		<< amount[1] - bal[1] * d << " "
		<< amount[2] - bal[2] * d << endl;
	


	return 0;
}