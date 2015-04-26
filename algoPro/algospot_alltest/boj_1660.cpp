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
	std::ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> vc;
	vector<int> result;
	vector<int> counting(300001,123456789);
	int i = 0;
	int c = 2;
	vc.push_back(1);		
	result.push_back(1);
	while (result[i] <= n){
		++i;
		vc.push_back(vc[i - 1] + c);
		++c;
		result.push_back(result[i - 1] + vc[i]);		
	}

	counting[0] = 0;
	int sz = result.size();
	for (int i = 0; i < sz; ++i){
		for (int j = 0; j <= n; ++j){
			if (j - result[i] < 0) continue;
			counting[j] = min(counting[j], counting[j - result[i]] + 1);
		}
	}

	cout << counting[n] << endl;

	return 0;
}