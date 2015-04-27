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

struct ohm{
	string name;
	long long val;
	long long mul;
};

#pragma warning (disable:4996)
ifstream in("input.txt");

int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
#endif
	

	vector<ohm> ohms(10);
	ohms[0].name = "black";
	ohms[1].name = "brown";
	ohms[2].name = "red";
	ohms[3].name = "orange";
	ohms[4].name = "yellow";
	ohms[5].name = "green";
	ohms[6].name = "blue";
	ohms[7].name = "violet";
	ohms[8].name = "grey";
	ohms[9].name = "white";


	ohms[0].val = 0;
	ohms[0].mul = 1;
	for (int i = 1; i < 10; i++){
		ohms[i].val = i;
		ohms[i].mul = ohms[i - 1].mul * 10;
	}

	string a, b, c;
	cin >> a >> b >> c;

	long long ans = 0;
	for (int i = 0; i < 10; i++){
		if (a == ohms[i].name)
			ans += ohms[i].val * 10;
	}

	for (int i = 0; i < 10; i++){
		if (b == ohms[i].name)
			ans += ohms[i].val;
	}

	for (int i = 0; i < 10; i++){
		if (c == ohms[i].name)
			ans *= ohms[i].mul;
	}
	
	cout << ans << endl;
	return 0;
}