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

vector<string> housemap;
int mx[] = { 1, 0, -1, 0 };
int my[] = { 0, 1, 0, -1 };

int mapping(int cy, int cx){
	housemap[cy][cx] = '0';
	int ret = 1;
	for (int i = 0; i < 4; i++){
		if (housemap[cy + my[i]][cx + mx[i]] == '1'){
			
			ret+= mapping(cy + my[i], cx + mx[i]);
		}
	}
	return ret;
}


int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	string tmp(n + 2, '0');
	housemap = vector<string>(vector<string>(n + 2, tmp));

	for (int i = 1; i < n + 1; i++){
		string str;
		cin >> str;
		housemap[i] = "0" + str + "0";
	}

	int ans = 0;
	vector<int> sz;

	for (int i = 1; i < n + 1; i++){
		for (int j = 1; j < n + 1; j++){
			if (housemap[i][j] == '1'){				
				ans++;
				sz.push_back(mapping(i, j));
			}
		}
	}
	cout << ans << endl;
	sort(sz.begin(), sz.end());
	for (int i = 0; i< sz.size(); i++)
		cout << sz[i] << endl;

	return 0;
}