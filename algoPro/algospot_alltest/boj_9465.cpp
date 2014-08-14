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
vector<vector<int> >sticker;
vector<pair<int,int> > order;
vector<vector<bool> >canuse;

int N;
void making(int line, int cur, bool val){
	canuse[(line + 1) % 2][cur] = val;
	canuse[line][cur] = val;
	if (cur != 0)
		canuse[line][cur - 1] = val;
	if (cur != N - 1)
		canuse[line][cur + 1] = val;
	return;
}
int checking(int line, int cur){
	if (cur < 0 || cur >= N)
		return 987654321;

	int psum = 0;
	if (cur != 0 && canuse[line][cur - 1])
		psum += sticker[line][cur - 1];

	if (cur != N - 1 && canuse[line][cur + 1])
		psum += sticker[line][cur + 1];

	if(canuse[(line+1)%2][cur])
		psum += sticker[(line+1)%2][cur];

	return psum;
}

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	std::ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--){
		int n;
		cin >> n;
		int doublen = 2 * n;
		N = n;
		sticker = vector<vector<int> >(2, vector<int>(n, -1));
		order = vector<pair<int,int> >(doublen);
		canuse = vector<vector<bool> >(2,vector<bool>(n, true));

		
		for (int i = 0; i < doublen; i++){
			int a;
			cin >> a;
			sticker[i / n][i%n] = a;
			order[i] = make_pair(a, i);
		}
		sort(order.begin(), order.end());
		reverse(order.begin(), order.end());
		
		int sum = 0;

		for (int i = 0; i < doublen; i++){
			int pos = order[i].second;
			if (canuse[pos / n][pos%n]){
				int curv = checking(pos / n, pos%n);
				int leftv = checking(pos / n, pos%n - 1);
				int rightv = checking(pos / n, pos%n + 1);
				int otherlinev = checking((pos / n + 1) % 2, pos%n);

				if (curv <= leftv && curv <= rightv && curv <= otherlinev){
					sum += order[i].first;
					making(pos / n, pos%n, false);
				}
				else
					canuse[pos / n][pos%n] = false;
			}
			
		}

		cout << sum << endl;

		
		

	}
	return 0;
}