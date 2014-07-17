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

	
	vector<string> numbers = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
	vector<vector<int> > alphas;
	vector<int> tmp(26,0);
	for (int i = 0; i < 11; i++)
		alphas.push_back(tmp);
	
	for (int i = 0; i < 11; i++){
		int sz = numbers[i].length();
		for (int j = 0; j < sz; j++)
		{
			alphas[i][numbers[i][j]- 'a']++;
		}
	}
	map<string, int> mapnumbers;
	for (int i = 0; i < 11; i++)
	{
		mapnumbers.insert(make_pair(numbers[i], i));
	}

	while (tc--){
		int a, b, c = -1;
		vector<string> vc;
		string tmpstr;
		for (int i = 0; i < 5; i++){
			cin >> tmpstr;
			vc.push_back(tmpstr);
		}
		a = mapnumbers[vc[0]];
		b = mapnumbers[vc[2]];
		
		char sw = vc[1][0];
		switch (sw)
		{
		case '+':
			c = a + b;
			break;
		case '-':
			c = a - b;
			break;
		case '*':
			c = a*b;
			break;
		default:
			break;
		}

		vector<int> countAl(26, 0);
		int sz = vc[4].length();
		for (int i = 0; i < sz; i++)
			countAl[vc[4][i] - 'a']++;


		bool flg = false;

		if (c < 0 || c > 10)
			cout << "No" << endl;
		else{
			if (alphas[c] == countAl)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		

	
	}
	return 0;
}