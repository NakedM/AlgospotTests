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

vector<int> split(const vector<int>& vc, int s, int e){
	return vector<int>(vc.begin() + s, vc.begin() + e + 1);
}

void postord(const vector<int>& preord, const vector<int>& inord){
	
	if (preord.empty()) return;

	int root = preord[0];
	int slength = find(inord.begin(), inord.end(), root) - inord.begin();

	postord(split(preord, 1, slength), split(inord, 0, slength));
	postord(split(preord, slength+1, preord.size()-1), split(inord, slength+1, inord.size()-1));

	cout << root << " ";
}

int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		int n;
		cin >> n;
		vector<int> preord(n);
		vector<int> inord(n);
		for (int i = 0; i < n; i++)
			cin >> preord[i];

		for (int i = 0; i < n; i++)
			cin >> inord[i];

		postord(preord, inord);
		cout << endl;
	}
	return 0;
}