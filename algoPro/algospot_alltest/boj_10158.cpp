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
	int w, h;
	int px, py;
	int t;
	cin >> w >> h >> px >> py >> t;
	int wt = t, ht = t;
	
	if (w - px >= wt)
		px += wt;
	else{
		wt -= (w - px);
		px = w;
		if (wt >= w * 2)
			wt %= (w * 2);

		if (wt >= w){
			wt -= w;
			px = wt;

		}
		else{
			px -= wt;
		}
	}

	if (h - py >= ht)
		py += ht;
	else{
		ht -= (h - py);
		py = h;
		if (ht >= h * 2)
			ht %= (h * 2);

		if (ht >= h){
			ht -= h;
			py = ht;

		}
		else{
			py -= ht;
		}
	}
	cout << px << " " << py << endl;

	return 0;
}