#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include<vector>

#pragma warning (disable : 4996)

using namespace std;


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;

	cin.ignore();

	vector<string> oringinalStr(n);
	vector<bool> usedStr(n,false);
	vector<string> memoStr(m);
	vector<bool> memoUsed(m, false);

	string tmpstr;
	for (int i = 0; i < n; i++)
	{
		getline(cin, tmpstr);
		oringinalStr[i] = tmpstr;
	}

	for (int i = 0; i < m; i++)
	{
		getline(cin, tmpstr);
		memoStr[i] = tmpstr;
	}

	int count = 0;
	for (int i = 0; i < n; i++){
		if (usedStr[i])
			continue;
		for (int j = 0; j < m; j++){
			if (memoUsed[j])
				continue;
			int pos = 0;
			int mlen = memoStr[j].length();
			while (pos < mlen)
			{
				if (oringinalStr[i][pos] == memoStr[j][pos])
				{
					++pos;
				}
				else
					break;
			}
			if (pos == mlen){
				usedStr[i] = true;
				memoUsed[j] = true;
				count++;
				continue;
			}
		}
	}

	cout << count << endl;

	return 0;
}