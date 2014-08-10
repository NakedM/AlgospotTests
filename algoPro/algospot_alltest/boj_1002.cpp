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

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		int x1, y1, r11, x2, y2, r22;
		cin >> x1 >> y1 >> r11 >> x2 >> y2 >> r22;
		int x = x1 - x2;
		int y = y1 - y2;
		double dist = sqrt(x*x + y*y);
		double r1 = double(r11);
		double r2 = double(r22);

		if (x1 == x2 && y1 == y2)
		{
			if (r1 == r2)
				cout << -1 << endl;
			else
				cout << 0 << endl;
		}
		else if(dist <= r1 || dist <= r2){
			if (dist + r1 == r2 || dist + r2 == r1)
				cout << 1 << endl;
			else if (dist + r1 < r2 || dist + r2 < r1)
				cout << 0 << endl;
			else
				cout << 2 << endl;
		}
		else {
			if (dist == r1+r2)
				cout << 1 << endl;
			else if (dist > r1 + r2)
				cout << 0 << endl;
			else
				cout << 2 << endl;
		}


	}
	return 0;
}