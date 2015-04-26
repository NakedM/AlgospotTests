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

vector<vector<bool> > vc;

int n, m;
void chooseIcecream(int cho, int count,long long& ans){
	if (count == 3)
	{
		ans++;
		//cout << endl;
		return;
	}

	for (int i = cho+1; i < n + 1; i++){
		if (vc[cho][i]){
			//cout << i << " ";
			chooseIcecream(i, count + 1, ans);
		}
		
	}
	//cout << endl;
	return;
}


int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
#endif
	cin >> n >> m;

	vc = vector<vector<bool> >(201, vector<bool>(201, true));
	
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		vc[a][b] = false;
		vc[b][a] = false;
	}

	for (int i = 0; i < 201; i++)
		vc[i][i] = false;

	long long ans = 0;
	
	chooseIcecream(0, 0, ans);
	cout << ans << endl;


	return 0;
}