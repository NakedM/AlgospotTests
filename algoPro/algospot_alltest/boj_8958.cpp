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

int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
#endif
		string str;
		cin >> str;
		int total = 10;
		int len = str.length();
		for (int i = 1; i < len; i++){
			if (str[i] == str[i - 1])
				total += 5;
			else
				total += 10;
		}
		cout << total << endl;

	return 0;
}