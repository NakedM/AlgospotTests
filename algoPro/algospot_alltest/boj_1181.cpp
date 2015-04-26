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

bool comp(string a, string b){
	if (a.length() != b.length())
		return a.length() < b.length();
	else
		return a < b;
}

#pragma warning (disable:4996)
ifstream in("input.txt");

int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	vector<string> vcstr;

	string str;
	bool fl = true;
	for (int i = 0; i < n; i++){
		cin >> str;
		int sz = vcstr.size();
		fl = true;
		for (int j = 0; j < sz; j++){
			if (vcstr[j] == str)
				fl = false;
		}
		if (fl)
			vcstr.push_back(str);
	}

	sort(vcstr.begin(), vcstr.end(), comp);
	

	for (int i = 0; i < vcstr.size(); i++){		
			cout << vcstr[i] << endl;
	}


	return 0;
}