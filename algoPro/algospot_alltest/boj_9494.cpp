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
	int n;
	while (true){
		cin >> n;
		if (n == 0)
			break;
		cin.ignore();
		vector<string> str(n);
		for (int i = 0; i < n; i++){
			getline(cin, str[i]);
			str[i] += ' ';
		}

		int s = 0;
		int pos = 0;
		for (int i = 0; i < n; i++){			
			int tmp = str[i].find(' ', pos);
			if (tmp != -1)
				pos = tmp;			
		}
		cout << pos + 1 << endl;
	}
	return 0;
}