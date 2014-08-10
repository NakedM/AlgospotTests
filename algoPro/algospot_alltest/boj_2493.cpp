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
	vector<int> val(n+1, 0);

	for (int i = n; i >= 0; i--){
		int ind = vc[i].second;
		for (int j = ind; j<=n; j++){
			if (ind > val[j])
				val[j] = ind;
			else
				break;
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