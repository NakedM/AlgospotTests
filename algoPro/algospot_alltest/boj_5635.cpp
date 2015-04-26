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
struct person{
	string name;
	int day;
	int month;
	int year;
};
bool comp(person a, person b){
	if (a.year != b.year)
		return a.year > b.year;
	if (a.month != b.month)
		return a.month > b.month;	
	return a.day > b.day;
}

int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
#endif	
	int n;
	cin >> n;
	string name;
	int d, m, y;
	vector<person> vcs;
	person p;
	for (int i = 0; i < n; i++){
		cin >> p.name >> p.day >> p.month >> p.year;
		vcs.push_back(p);
	}
	sort(vcs.begin(), vcs.end(), comp);
	
	cout << vcs[0].name << endl;
	cout << vcs[vcs.size() - 1].name << endl;

	return 0;
}