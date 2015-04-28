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
	int n, m;
	cin >> n >> m;
	vector<string> miro(n+2);
	string str(m+2, '0');
	miro[0] = miro[n+1] = str;
	
	for (int i = 1; i <= n; i++){
		str.clear();
		str += '0';
		string tmp;
		cin >> tmp;
		str += tmp + '0';

		miro[i] = str;
	}

	vector<vector<int> > steps(n+2, vector<int>(m+2, INF));
	steps[1][1] = 1;
	queue<pair<int,int> > que;
	que.push(make_pair(1, 1));

	while (!que.empty()){
		int herey =	que.front().first;
		int herex = que.front().second;
		que.pop();

		int therey, therex;
		therey = herey;
		therex = herex+1;
		if (miro[therey][therex] == '1' && steps[therey][therex] > steps[herey][herex] + 1){
			que.push(make_pair(therey, therex));
			steps[therey][therex] = steps[herey][herex] + 1;
		}
		therey = herey+1;
		therex = herex;
		if (miro[therey][therex] == '1' && steps[therey][therex] > steps[herey][herex] + 1){
			que.push(make_pair(therey, therex));
			steps[therey][therex] = steps[herey][herex] + 1;
		}

		therey = herey;
		therex = herex-1;
		if (miro[therey][therex] == '1' && steps[therey][therex] > steps[herey][herex] + 1){
			que.push(make_pair(therey, therex));
			steps[therey][therex] = steps[herey][herex] + 1;
		}
		therey = herey-1;
		therex = herex;
		if (miro[therey][therex] == '1' && steps[therey][therex] > steps[herey][herex] + 1){
			que.push(make_pair(therey, therex));
			steps[therey][therex] = steps[herey][herex] + 1;
		}
	}

	cout << steps[n][m] << endl;

	return 0;
}