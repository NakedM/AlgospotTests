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

vector<string> dices;
int n;
int val;
int cache[14][1010];

int kindsof(string d){
	if (d == "d4")
		return 4;
	if (d == "d6")
		return 6;
	if (d == "d8")
		return 8;
	if (d == "d10")
		return 10;
	if (d == "d12")
		return 12;
	if (d == "d20")
		return 20;

	return -1;
}

int makingval(int curv, int ind){
	if (ind == n)
	{
		if (curv == val)
			return 1;
		
		return 0;
	}
	int m = kindsof(dices[ind]);
	
	int& ret = cache[ind][curv];
	if (ret != -1)
		return ret;

	ret = 0;
	
	for (int i = 1; i <= m; i++){
		ret += makingval(curv + i, ind + 1);
	}
	return ret;
}

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	while (1){
		
		dices.clear();
		memset(cache, -1, sizeof(cache));
		
		cin >> n;
		if (n == 0)
			break;
		string str;
		for (int i = 0; i < n; i++){
			cin >> str;
			dices.push_back(str);
		}

		int allv = 1;
		for (int i = 0; i < n; i++)
			allv *= kindsof(dices[i]);

		cin >> val;
		int result = makingval(0, 0);
		double r = double(result) / double(allv);

		cout << fixed;
		cout.precision(5);
		//cout << r << endl;
		cout <<result<<" "<< r << endl;
	}
	return 0;
}