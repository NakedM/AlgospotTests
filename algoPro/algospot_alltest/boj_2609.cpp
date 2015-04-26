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

int gcd(int p, int q){
	return q == 0 ? p : gcd(q, p % q);
}

int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
#endif
	int a, b;
	cin >> a >> b;
	int g = gcd(a,b);
	cout << g << endl;
	cout << (a*b) / g << endl;
	return 0;
}