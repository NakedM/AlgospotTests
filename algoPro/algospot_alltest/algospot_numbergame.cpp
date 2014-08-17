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

const int MINN = -987654321;
vector<int> nums;
vector<vector<int> > cache;

int game(int left, int right){
	if (left > right)
		return 0;

	int& ret = cache[left][right];
	if (ret != MINN)
		return ret;

	ret = max(nums[left] - game(left + 1, right), nums[right] - game(left, right - 1));

	if (right - left + 1 >= 2){
		ret = max(ret, -game(left + 2, right));
		ret = max(ret, -game(left, right - 2));
	}
	return ret;
}



int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		int n;
		cin >> n;
		nums = vector<int>(n);
		for (int i = 0; i < n; i++)
			cin >> nums[i];

		cache = vector<vector<int> >(n, vector<int>(n, MINN));

		int result = game(0, n - 1);
		cout << result << endl;

	}
	return 0;
}