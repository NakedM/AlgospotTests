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
using namespace std;

#pragma warning (disable:4996)
ifstream in("input.txt");

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	vector<bool> sosu(201, true);
	vector<int> vcsosu;
	sosu[0] = false;
	sosu[1] = false;
	for (int i = 2; i < 201; i++){
		if (sosu[i]){
			for (int j = i + i; j < 201; j += i)
				sosu[i] = false;
		}
	}

	for (int i = 2; i < 201; i++){
		if (sosu[i])
			vcsosu.push_back(i);
	}

	int tc;
	cin >> tc;
	while (tc--){
		int M, N, x, y;

		cin >> M >> N >> x >> y;
		
		vector<int> yacsu(201, 0);
		bool flg = false;
		int tmpM = M, tmpN = N;
		int smallestmax = 1;
		
		bool f = true;
		while (f){
			int minn = min(tmpM, tmpN);
			f = false;
			for (int i = 2; i <= minn; i++){
				if (tmpM % i == 0 && tmpN % i == 0){
					smallestmax *= i;
					tmpM /= i;
					tmpN /= i;
					f = true;
					break;
				}
			}
		}
		smallestmax *= (tmpM*tmpN);
		int maxop = smallestmax / M;

		int count = x;

		if (N == y)
			y = 0;

		for (int j = 0; j < maxop; j++){
			if (y == count % N){
				flg = true;
				break;
			}
			count += M;
		}
		if (flg)
			cout << count << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}