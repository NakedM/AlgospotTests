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

struct star{
	int x;
	int y;
	int r;
};

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int n;
		cin >> n;
		vector<star> st;
		for (int i = 0; i < n; i++){
			star s;
			cin >> s.x >> s.y >> s.r;
			st.push_back(s);
		}

		int count = 0;
		for (int i = 0; i < n; i++){
			bool start = false, end = false;
			int x = st[i].x - x1;
			int y = st[i].y - y1;
			int r = st[i].r*st[i].r;
			int dist = x*x + y*y;
			if (dist < r)
				start = true;
			x = st[i].x - x2;
			y = st[i].y - y2;
			dist = x*x + y*y;

			if (dist < r)
				end = true;

			if (start^end)
				count++;
		}

		cout << count << endl;

	}
	return 0;
}