#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits>
#include<bitset>
#include<deque>
#include<set>

#pragma warning (disable:4996)
using namespace std;

ifstream in("input.txt");

vector<int> result;
void cal()
{
	
	int sx = 500500, sy = 500500;
	set<pair<int, int> > points[2];
	points[0].insert(make_pair(sy, sx));

	bool flg = false;

	set<pair<int, int> >::iterator it;
	for (int i = 1; i <= 1000; i++)
	{
		int sz = points[flg].size();
		for (int j = 0; j < sz; j++)
		{
			it = points[flg].begin();
			int ty = it->first;
			int tx = it->second;

			points[!flg].insert(make_pair(ty + i, tx));
			points[!flg].insert(make_pair(ty - i, tx));
			points[!flg].insert(make_pair(ty, tx + i));
			points[!flg].insert(make_pair(ty, tx - i));

			points[flg].erase(it);
		}
		flg = !flg;
		result[i] = sz % 20130728;
		
		cout << result[i] << endl;
	}

	/*int count = points[flg].size();
	count %= 20130728;*/
}

//시간초과
int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	result = vector<int>(1010, 0);
	cal();
	while (tc--){		
		int n;
		cin >> n;	
		
		cout << result[n] << endl;

	}
	return 0;
}