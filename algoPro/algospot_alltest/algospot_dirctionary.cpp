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

ifstream in("input.txt");

bool alphabet[26][26];
string str;
bool invalidflg;
void printt(int k)
{
	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i][k])
		{
			if (alphabet[k][i])
				invalidflg = false;
			printt(i);
			break;
		}
	}
	str += ('a' + k);
	for (int i = 0; i < 26; i++)
	{
		if (alphabet[k][i])
		{
			if (alphabet[i][k])
				invalidflg = false;
			printt(i);
			break;
		}
	}
	return;
}

int main(){
#ifdef _HONG   
	freopen("input.txt", "r", stdin);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		int n;
		vector<string> vc;

		memset(alphabet, 0, sizeof(alphabet));
		
		cin >> n;
		string tmp;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			vc.push_back(tmp);
		}
		for (int i = 1; i < n; i++)
		{
			int before = i - 1;
			int len = min(vc[i].size(), vc[before].size());

			for (int h = 0; h < len; h++)
			{
				if (vc[before][h] != vc[i][h])
				{
					int first = vc[before][h]-'a';
					int second = vc[i][h] - 'a';
					alphabet[first][second] = true;
					break;
				}
			}
		}

		invalidflg = false;
		printt(0);
		
		


	}
	return 0;
}