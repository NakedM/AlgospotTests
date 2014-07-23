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

struct Comparator {
	const vector<int>& group;
	int t;
	Comparator(const vector<int>& _group, int _t) : group(_group), t(_t) {}

	bool operator () (int a, int b){
		if (group[a] != group[b]) return group[a] < group[b];

		return group[a + t] < group[b + t];
	}
};

vector<int> getSuffixArray(const string& s){
	int n = s.size();

	int t = 1;
	vector<int> group(n + 1);
	for (int i = 0; i < n; ++i)
		group[i] = s[i];

	group[n] = -1;

	vector<int> perm(n);
	for (int i = 0; i < n; i++)
		perm[i] = i;

	while (t < n){

		Comparator compareUsing2T(group, t);
		sort(perm.begin(), perm.end(), compareUsing2T);
		for (int i = 0; i < group.size(); i++)
			cout << group[i] << " ";
		cout << endl;

		t *= 2;
		if (t >= n) break;

		vector<int> newGroup(n + 1);
		newGroup[n] = -1;
		newGroup[perm[0]] = 0;
		for (int i = 1; i < n; i++){
			if (compareUsing2T(perm[i - 1], perm[i]))
				newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
			else
				newGroup[perm[i]] = newGroup[perm[i - 1]];
		}
		group = newGroup;
	}
	return perm;
}

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		string str;
		cin >> str;

		vector<int> vc = getSuffixArray(str);

		for (int i = 0; i < vc.size(); i++)
			cout << vc[i] << " ";
		cout << endl;


	}
	return 0;
}