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

vector<int> getPartialMatch(const string& pat){
	int m = pat.size();
	vector<int> failf(m, 0);

	int begin = 1, matched = 0;

	while (begin + matched <m){
		if (pat[begin + matched] == pat[matched]){
			++matched;
			failf[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				++begin;
			else {
				begin += matched - failf[matched - 1];
				matched = failf[matched - 1];
			}
		}
	}
	return failf;
}



int kmpSearch(const string& txt, const string& pat){
	int n = txt.size(), m = pat.size();
	
	vector<int> failf = getPartialMatch(pat);

	int begin = 0, matched = 0;
	while (begin < n) {
		if (matched < m && txt[begin + matched] == pat[matched]){
		++matched;

		if ((begin + matched) == n)
			return matched;		
		}
		else{
			if (matched == 0)
				++begin;
			else{
				begin += matched - failf[matched - 1];

				matched = failf[matched - 1];
			}
		}
	}
	return 0;
}

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		string txt;
		cin >> txt;

		string revtxt = txt;
		int len = txt.length();
		int halflen = len / 2;
		for (int i = 0; i < halflen; i++){
			swap(revtxt[i], revtxt[len - 1 - i]);
		}

		int matching = kmpSearch(txt, revtxt);
		int result = len + len - matching;

		cout << result << endl;
	}
	return 0;
}