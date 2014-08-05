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

long long cache[1001];

long long grid(int w){
	if (w == 1)
		return 1;
	if (w == 2)
		return 5;

	long long& ret = cache[w];
	if (ret != -1)
		return ret;
	ret = 0;
	
	if (w % 2 == 1)
		ret += grid(w - 1)*2 + 1;
	else
		ret += grid(w - 1) + grid(w - 2) * 5 + 3;

	return ret;
}

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;


	for(int t = 1;t<=tc;t++){
		int n;
		cin >> n;
		memset(cache, -1, sizeof(cache));


		long long result = grid(n);
		cout << t << " " << result << endl;
	}
	return 0;
}