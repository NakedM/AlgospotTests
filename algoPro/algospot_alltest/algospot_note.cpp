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

#pragma warning (disable:4996)
ifstream in("input.txt");

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	
		//cout << "Example " << k << endl;

		
	int tmp; 
	int ind = 0;
	vector<int> vc(9);
	while (cin >> tmp){
		vc[ind + 1] = tmp;			
		if (ind == 7){
			if (vc[1] == 1 && vc[2] == 2 &&
				vc[3] == 3 && vc[4] == 4 &&
				vc[5] == 5 && vc[6] == 6 &&
				vc[7] == 7 && vc[8] == 8)
				cout << "ascending" << endl;
			else if (vc[1] == 8 && vc[2] == 7 &&
				vc[3] == 6 && vc[4] == 5 &&
				vc[5] == 4 && vc[6] == 3 &&
				vc[7] == 2 && vc[8] == 1)
				cout << "descending" << endl;
			else
				cout << "mixed" << endl;
		}
		ind++;
		ind %= 8;		
	}
	return 0;
}