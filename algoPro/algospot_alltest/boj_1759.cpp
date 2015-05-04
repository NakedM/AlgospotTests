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

int n, c;
vector<char> moum;
vector<char> jaum;
vector<char> alpha;

void security(int mo, int ja, int len, int ind, string str){
	if (len == n){
		if (mo >= 1 && ja >= 2)
			cout << str << endl;
		else
			return;
	}
	
	for (int i = ind; i < c; i++){
		//str += alpha[i];
		if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u')
			security(mo + 1, ja, len + 1, i + 1, str + alpha[i]);
		else
			security(mo, ja + 1, len + 1, i + 1, str + alpha[i]);
	}
	return;
}

int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
#endif
	
	cin >> n >> c;
	
	alpha = vector<char>(c);
	for (int i = 0; i < c; i++){
		cin >> alpha[i];
	}

	sort(alpha.begin(), alpha.end());
	security(0, 0, 0, 0, "");

	return 0;
}