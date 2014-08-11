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
	int n;
	cin >> n;
	vector<int>  a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<int> b(n);
	for (int i = 0; i < n; i++)
		cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());

	int sum = 0;
	for (int i = 0; i < n; i++){
		sum += (a[i] * b[i]);
	}
	cout << sum << endl;


	return 0;
}