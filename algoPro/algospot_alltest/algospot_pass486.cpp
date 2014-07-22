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
const int TM = 1000 * 1000 * 10;
 
int factor[TM + 1];

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif

	int halftm = TM/2;
	
	factor[0] = 0;
	factor[1] = 1;

	for (int i = 2; i <= TM; i++)
		factor[i] = 2;

	for (int i = 2; i <= halftm; i++){		
		for (int j = i + i; j <= TM; j += i){
			factor[j] += 1;
		}
	}
		
	int tc;
	cin >> tc;
	while (tc--){
		int n, low, high;
		cin >> n >> low >> high;

		int count = 0;
		for (int i = low; i <= high; i++){
			if (factor[i] == n)
				count++;
		}

		cout << count << endl;


	}
	return 0;
}