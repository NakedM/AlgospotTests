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

vector<vector<bool> > pann;
vector<vector<int> > cache;
int len;
int N;

int diamond(int u, int v, int width, int maxw){
	if (width < 0)
		return maxw;
	if (u >= N)
		return 0;
	if (!pann[u][v])
		return 0;

	int& ret = cache[u][v];
	if (ret >= maxw)
		return cache[u][v];

	for (int j = v - width; j <= v + width; j++){
		if (j < 0 || j >= len)
			return 0;

		if (!pann[u][j])
			return 0;
	}
	maxw = max(maxw, width);

	if (width >= maxw)
		ret = max(diamond(u + 1, v, width - 1, maxw),diamond(u + 1, v, width + 1, maxw));
	else
		ret = max(ret, diamond(u + 1, v, width - 1, maxw));

	return ret;	
}

int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		int n;
		cin >> n;
		N = n;
		
		vector<int> shaps(n, 0);
		string str;
		cin >> str;
		len = str.length();
		pann = vector<vector<bool> > (n, vector<bool>(len, false));
		cache = vector<vector<int> >(n, vector<int>(len, -1));

		for (int j = 0; j < len; j++){
			if (str[j] == '.')
				pann[0][j] = false;
			else
			{
				pann[0][j] = true;
			}
		}
		for (int i = 1; i < n; i++){
			for (int j = 0; j < len; j++){
				char c;
				cin >> c;
				if (c == '.')
					pann[i][j] = false;
				else{
					pann[i][j] = true;
				}
			}
		}

		int result = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < len; j++){
				if(pann[i][j])
					result = max(result, diamond(i, j, 0, 0));
			}
		}
		cout << result*2 + 1 << endl;
	}
	return 0;
}