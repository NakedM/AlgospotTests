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
	int n, m;
	cin >> n >> m;

	int i;
	vector<int> result;
	for (i = m; i <= 100; i++){
		result.clear();
		if (i >= n)
			break;

		if (i % 2 == 1){
			int r = n % i;
			int v = n / i;	
			int s = v - (i / 2);
			if (r == 0 && s >= 0)
			{				
				for (int j = s; j < s + i; j++)
					result.push_back(j);

				break;
			}

			if (s < 0)
				break;
		}
		else{
			int r = n % i;
			int v = n / i;			
			if (r == i / 2)
			{
				int s = v - (i / 2) + 1;
				for (int j = s; j < s + i; j++)
					result.push_back(j);

				break;
			}
		}
	}

	if (i == 101 || result.empty())
		cout << -1 << endl;
	else
	{
		int sz = result.size();
		//int sums = 0;
		for (int i = 0; i < sz; i++)
		{
			cout << result[i];
			//sums += result[i];
			if (i != sz - 1)
				cout << " ";
			else
				cout << endl;
		}
		//cout << sums << endl;
	}

	
	return 0;
}