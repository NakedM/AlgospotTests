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
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif

	vector<long long> arr(101);
	arr[0] = arr[1] = arr[2] = 1;
	arr[3] = arr[4] = 2;
	arr[5] = 3;
	arr[6] = 4;
	arr[7] = 5;
	arr[8] = 7;
	arr[9] = 9;

	for (int i = 10; i < 101; i++){
		arr[i] = arr[i - 1] + arr[i - 5];
	}
	int tc;
	cin >> tc;
	while (tc--){
		int n;
		cin >> n;

		cout << arr[n - 1] << endl;
	}
	return 0;
}