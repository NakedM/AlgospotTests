#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include<string>
#include<vector>

#pragma warning (disable : 4996)

using namespace std;


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int tc;
	cin >> tc;
	while (tc--){
		string star;
		string fan;
		cin >> star;
		cin >> fan;
		int starlen = star.length(), fanlen = fan.length();
		vector<int> vcStar(starlen, -1);
		vector<int> vcFan(fanlen, -1);

		for (int i = 0; i < starlen; i++)
		{
			if (star[i] == 'F')
				vcStar[i] = 0;
			else
				vcStar[i] = 1;
		}
		for (int i = 0; i < fanlen; i++)
		{
			if (fan[i] == 'F')
				vcFan[i] = 0;
			else
				vcFan[i] = 1;
		}

		int count = 0;

		for (int i = 0; i <= fanlen - starlen; i++)
		{
			int multi = 0;
			for (int j = 0; j < starlen; j++)
			{
				multi += (vcStar[j] * vcFan[i+j]);
			}
			if (multi == 0)
				++count;
		}

		cout << count << endl;

		
	}

	return 0;
}