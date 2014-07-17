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
#include<map>
using namespace std;

ifstream in("input.txt");

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	
	map<string, int> week;
	week.insert(make_pair("Sunday", 0));
	week.insert(make_pair("Monday", 1));
	week.insert(make_pair("Tuesday", 2));
	week.insert(make_pair("Wednesday", 3));
	week.insert(make_pair("Thursday", 4));
	week.insert(make_pair("Friday", 5));
	week.insert(make_pair("Saturday", 6));

	vector<int> month = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (tc--){
		int m, d;
		string days;
		cin >> m >> d >> days;
		
		vector<int> result(7, 0);
		int tmpdays = week[days];
		int tmpd = d;
		result[week[days]] = d;
		while (tmpdays >= 1)
		{
			result[--tmpdays] = --tmpd;
			if (tmpd < 1)
			{
				if (m - 1 != 0)
					tmpd = month[m - 1];
				else
					tmpd = month[12];
				result[tmpdays] = tmpd;
			}
		}
		tmpdays = week[days];
		tmpd = d;
		while (tmpdays < 6)
		{
			result[++tmpdays] = ++tmpd;
			if (tmpd > month[m])
			{
				tmpd = 1;
				result[tmpdays] = tmpd;
			}
		}

		for (int i = 0; i < 7; i++)
		{
			cout << result[i];
			if (i != 6)
				cout << " ";
			else
				cout << endl;
		}

	}
	return 0;
}