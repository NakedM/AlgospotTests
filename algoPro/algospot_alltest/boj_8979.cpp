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

struct country{
	int num;
	int gold;
	int silver;
	int bronze;
};

bool comp(country a, country b){
	if (a.gold != b.gold)
		return a.gold > b.gold;
	if (a.silver != b.silver)
		return a.silver > b.silver;
	return a.bronze > b.bronze;
}

int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
#endif
	int n, k;
	cin >> n >> k;	
	
	vector<country> vc(n);

	for (int i = 0; i < n; i++){
		country ct;
		cin >> ct.num >> ct.gold >> ct.silver >> ct.bronze;
		vc[i] = ct;
	}

	sort(vc.begin(), vc.end(), comp);
	vector<int> ranking(n, 1);
	for (int i = 1; i < n; i++){
		if (vc[i - 1].gold == vc[i].gold &&vc[i - 1].silver == vc[i].silver &&vc[i - 1].bronze == vc[i].bronze)
			ranking[i] = ranking[i-1];
		else
			ranking[i] = ranking[i-1]+1;

		if (vc[i].num == k){
			cout << ranking[i] << endl;
			break;
		}
	}
	if (k == vc[0].num)
		cout << "1" << endl;

	return 0;
}