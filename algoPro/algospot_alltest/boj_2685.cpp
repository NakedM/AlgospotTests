#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits>
#include<sstream>
#include<bitset>
using namespace std;

#pragma warning (disable:4996)
ifstream in("input.txt");

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		int b, x, y;
		cin >> b >> x >> y;

		vector<int> strx;
		vector<int> stry;

		while (x > 0){
			int t = x%b;

			strx.push_back(t);
			
			x /= b;
		}
		

		while (y > 0){
			int t = y%b;

			stry.push_back(t);

			y /= b;
		}
	

		int lenx = strx.size();
		int leny = stry.size();
		int lenmin;
		int lenmax;
		
		vector<int> result;
		if (lenx >= leny)
		{
			lenmin = leny;
			lenmax = lenx;
			result = strx;
		}
		else{
			lenmin = lenx;
			lenmax = leny;
			result = stry;
		}		

		for (int i = 0; i < lenmin; i++)
		{
			int t = strx[i]+ stry[i];
			t %= b;
			
			result[i] = t;
		}

		int db = 1;
		long long answer = 0;
		for (int i = 0; i < lenmax; i++){
			answer += (result[i]* db);
			db *= b;
		}
		cout <<answer<< endl;

	}
	return 0;
}