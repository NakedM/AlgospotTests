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

const int len = 40;

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		vector<int> coin(8, 0);

		string str;
		cin >> str;

		for (int i = 0; i < len-2; i++){
			int sum = 0;
			int mul = 4;
			for (int j = 0; j < 3; j++){
				if (str[i + j] == 'H')
					sum += 1 * mul;
				mul /= 2;
			}
			coin[sum]++;
		}

		for (int i = 0; i < 8; i++){
			cout << coin[i];
			if (i != 7)
				cout << " ";
			else
				cout << endl;
		}


	}
	return 0;
}