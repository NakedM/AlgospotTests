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
	int n;
	cin >> n;
	vector<int> vc(n);
	for (int i = 0; i < n; i++)
		cin >> vc[i];

	int ans = 1;
	int c = 1;
	int same = 1;
	bool bl = true;


	for (int i = 1; i < n; i++){
		if (vc[i] == vc[i - 1])
			continue;

		if (vc[i] > vc[i - 1])
			bl = true;
		else
			bl = false;
		
		break;
	}
	for (int i = 1; i < n; i++){
		if (vc[i] > vc[i - 1]){
			if (bl)
				c++;
			else{
				bl = true;
				c = 2 + same - 1;				
			}
			same = 1;
		}
		else if (vc[i] < vc[i - 1]){
			if (bl){
				bl = false;
				c = 2 + same - 1;				
			}
			else
				c++;
			same = 1;
		}
		else{
			c++;
			same++;
		}
		ans = max(ans, c);
	}
	cout << ans << endl;
	
	return 0;
}