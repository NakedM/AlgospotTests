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
#include<set>
using namespace std;

const int INF = 987654321;

#pragma warning (disable:4996)
ifstream in("input.txt");

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
		vector<int> vc1(n);
		vector<int> vc2(n);
		vector<int> used1;
		//bitset<100001> bs1;
		
		bitset<100001> bs2;
		//bs1.set();	

		set<pair<int, int>> sett;

		for (int i = 0; i < n; i++)
			cin >> vc1[i];
		for (int i = 0; i < n; i++)
			cin >> vc2[i];

		for (int i = 0; i < n; i++){
			bs2.set();
			int upper = vc1[i];
			used1.push_back(upper);

			int pos = find(vc2.begin(), vc2.end(), upper) - vc2.begin();

			for(int k = 0;k<used1.size();k++)
				bs2.reset(used1[k]);

			for (int j = pos + 1; j < n; j++){
				bs2.reset(vc2[j]);
			}			
			for (int h = 1; h < n + 1; h++){
				if (bs2.test(h)){
					sett.insert(make_pair(min(upper, h), max(upper, h)));
				}
			}
		}
		cout << sett.size() << endl;
	}
	return 0;
}