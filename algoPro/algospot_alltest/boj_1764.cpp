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
#include<unordered_set>
using namespace std;

const int INF = 987654321;

#pragma warning (disable:4996)
ifstream in("input.txt");

int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	unordered_set<string> uset;
	vector<string> ans;
	string str;
	for (int i = 0; i < n; i++){
		cin >> str;
		uset.insert(str);
	}

	for (int i = 0; i < m; i++){
		cin >> str;
		if (uset.end() != uset.find(str))
			ans.push_back(str);
	}

	int sz = ans.size();
	cout << sz << endl;
	sort(ans.begin(), ans.end());
	for(int i=0;i<sz;i++)
		cout << ans[i] << endl;
		
	return 0;
}