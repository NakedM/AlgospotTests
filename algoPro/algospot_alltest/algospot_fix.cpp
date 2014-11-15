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
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		int k;
		cin >> k;

		vector<int> vc(vector<int>(k, 0));
		
		int cnt = 0;

		for (int i = 0; i < k; i++){
			cin >> vc[i];
			if (vc[i] == i + 1)
				cnt++;
		}

		cout << cnt << endl;



	}
	return 0;
}