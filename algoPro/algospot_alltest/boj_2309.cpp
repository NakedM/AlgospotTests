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

vector<int> littles;

bool knapsack(int start, int count, int sum, vector<int>& rs){
	if (count >= 7){
		if (sum != 100)
			return false;
		else
			return true;		
	}
	for (int i = start; i < 9; i++){
		rs.push_back(littles[i]);
		bool flg = knapsack(i + 1, count + 1, sum + littles[i], rs);
		if (flg)
			return true;
		else
			rs.pop_back();
	}

	return false;
}

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	littles.clear();
	for (int i = 0; i < 9; i++){
		int a;
		cin >> a;
		littles.push_back(a);
	}
	sort(littles.begin(), littles.end());

	vector<int> result;
	bool flg = knapsack(0, 0, 0, result);
	
	int sz = result.size();

	for (int i = 0; i < sz; i++){
		cout << result[i] << endl;
	}
	return 0;
}