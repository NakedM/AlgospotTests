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

// int inf = 1000000001;

#pragma warning (disable:4996)
ifstream in("input.txt");

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int n;
	cin >> n;
	vector<pair<int, int> > vc;
	vc.push_back(make_pair(987654321, 0));
	for (int i = 1; i <= n; i++){
		int a;
		cin >> a;
		vc.push_back(make_pair(a, i));
	}
	sort(vc.begin(), vc.end());
	vector<int> val(n+1, -1);

	for (int i = n-1; i >= 0; i--){
		for (int j = vc[i].second - 1; j >= 0; j--){
			if (val[j] != -1){
				val[vc[i].second] = j;
				break;
			}
			if (j == 0)
				val[vc[i].second] = 0;
		}
	}

	for (int i =1; i <= n; i++){
		cout << val[i];
		if (i != n )
			cout << " ";
		else
			cout << endl;
	}
	return 0;
}