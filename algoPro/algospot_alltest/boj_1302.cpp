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

const int INF = 987654321;

#pragma warning (disable:4996)
ifstream in("input.txt");


int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	int maxx = 1;
	int index = 0;
	vector<string> str(n);

	for (int i = 0; i < n; i++){
		cin >> str[i];	
	}
	sort(str.begin(), str.end());

	vector<int> cvc(n, 0);
	cvc[0] = 1;
	for (int i = 1; i < n; i++){
		if (str[i] == str[i - 1])
			cvc[i] = cvc[i - 1] + 1;
		else
			cvc[i] = 1;

		if (cvc[i] > maxx)
		{
			maxx = cvc[i];
			index = i;
		}
	}
	cout << str[index] << endl;
	return 0;
}