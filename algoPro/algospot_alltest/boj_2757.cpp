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
	while (1){
		string str;
		cin >> str;
		int len = str.length();
		long long n = 0, m = 0;

		int ind = 1;
		while (str[ind] != 'C'){
			n *= 10;
			n += (str[ind] - '0');
			ind++;
		}

		ind++;
		while (ind < len){
			m *= 10;
			m += (str[ind] - '0');
			ind++;
		}

		if (n == 0 && m == 0)
			break;

		vector<char> vc;
		while (m > 0){
			m -= 1;
			int remain = m % 26;
			char c = remain + 'A';
			vc.push_back(c);
			m /= 26;
			
		}

		int sz = vc.size();
		for (int i = sz - 1; i >= 0; i--)
			cout << vc[i];
		cout << n << endl;


	}
	return 0;
}