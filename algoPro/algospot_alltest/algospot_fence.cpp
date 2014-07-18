#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>

#pragma warning(disable:4996)

using namespace std;


vector<int> heights;


int solveprob(int low, int high){
	if (low == high)
		return heights[low];

	int mid = (low + high) / 2;

	int ret = max(solveprob(low, mid), solveprob(mid + 1, high));

	int le = mid, ri = mid + 1;

	int h = min(heights[le], heights[ri]);

	ret = max(ret, h * 2);

	while (low < le || ri < high)
	{
		if (ri < high && (low == le || heights[le-1] < heights[ri+1]))
		{
			ri++;
			h = min(h, heights[ri]);
		}
		else{
			le--;
			h = min(h, heights[le]);
		}

		ret = max(ret, h * (ri - le + 1));
	}
	return ret;
}
	


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		heights = vector<int>(n, 0);
		for (int i = 0; i < n; i++)
			cin >> heights[i];

		cout << solveprob(0, n - 1) << endl;
	}

	return 0;
}