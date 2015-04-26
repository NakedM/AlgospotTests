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
int w, h;
vector<vector<int> > vc;
int countLand(int y, int x){
	if (y >= h || x >= w || y <0 || x<0)
		return 0;
	
	for (int i = -1; i < 2; i++){
		for (int j = -1; j < 2; j++){
			if (y + i >= h || x + j >= w || y + i < 0 || x + j < 0)
				continue;
			if (vc[y + i][x + j] == 1){
				vc[y + i][x + j] = 0;
				countLand(y + i, x + j);
			}
		}
	}
	return 1;
}

int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
#endif
	
	while (true){
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		vc = vector<vector<int> >(h, vector<int>(w));
		for (int i = 0; i < h; i++){
			for (int j = 0; j < w; j++){
				cin >> vc[i][j];
			}
		}

		int sum = 0;
		for (int i = 0; i < h; i++){
			for (int j = 0; j < w; j++){
				if (vc[i][j] == 1){
					vc[i][j] = 0;
					sum += countLand(i, j);
				}
			}
		}
		cout << sum << endl;	
	}
	return 0;
}