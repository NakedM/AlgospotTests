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

struct rgb{
	vector<int> color;
};
vector<rgb> vc;
vector<vector<long long> > money;
int n;

long long painting(int c, int p){
	if (p == n)
		return 0;

	long long& ret = money[c][p];
	if (ret != -1)
		return ret;

	ret = INF;
	for (int i = 0; i < 3; i++){
		if (i == c)
			continue;
		ret = min(ret, painting(i, p + 1) + vc[p].color[i]);
		//cout << i << " " << p << " " << ret << endl;
	}
	return ret;
}

int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
#endif
	
	cin >> n;
	
	vc = vector<rgb>(n);
	money = vector<vector<long long> >(3, vector<long long>(n, -1));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 3; j++){
			int tmp;
			cin >> tmp;
			vc[i].color.push_back(tmp);
		}
	}


	long long k = INF;
	for(int i=0;i<3;i++)
		k = min(k, painting(i, 1)+vc[0].color[i]);
	
	cout << k << endl;
	return 0;
}