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

long long factorial[21];


void fact(){
	factorial[0] = 1;
	for (int i = 1; i < 21; i++){
		factorial[i] = factorial[i - 1] * i;
	}
}

long long sticks(int ptot, int maxpart){
	long long psum = 1;

	while(maxpart > 1){
		psum *= ptot - (--maxpart);
		ptot -= 1;
	}
	if (ptot == 0 && maxpart == 0){
		
		return 0;
	}

	return psum;
}

long long blenk(int n, int bl){
	long long psum = 0;

	if (n == 0)
		return 1;

	if (n < 0)
		return 0;

	for (int i = 1; i <= bl; i++){
		psum += (factorial[bl] / factorial[bl - i]) * factorial[n];
		n--;
		if (n == 0)
			break;
	}

	return psum;
}

int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif

	fact();
	int tc;
	cin >> tc;
	while (tc--){		
		int n, l, r;
		cin >> n >> l >> r;
		int ml = l - 1;
		int mr = r - 1;
		int ptot = ml + mr;
		long long stickcount = sticks(ptot, max(mr, ml));
		long long blenkcount = blenk(n - (ptot+1), ptot);
		


		//long long sum = 6402373705728000;

		cout << stickcount*blenkcount << endl;


	}
	return 0;
}