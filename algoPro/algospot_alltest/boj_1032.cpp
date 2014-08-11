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
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int n;
	cin >> n;
	vector<string> svc;
	for (int i = 0; i < n; i++){
		string str;
		cin >> str;
		svc.push_back(str);
	}

	int len = svc[0].length();
	vector<char> res;
	for (int j = 0; j < len; j++){
		char c = svc[0][j];
		bool flg = true;
		for (int i = 1; i < n; i++){
			if (c != svc[i][j])
				flg = false;
		}
		if (flg)
			res.push_back(c);
		else
			res.push_back('?');
	}

	for (int i = 0; i < len; i++){
		cout << res[i];
		if (i == len - 1)
			cout << endl;
	}

	return 0;
}