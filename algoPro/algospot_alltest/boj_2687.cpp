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

int returnVal(char c){
	switch (c)
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case 'A':
		return 10;
	case 'B':
		return 11;
	case 'C':
		return 12;
	case 'D':
		return 13;
	case 'E':
		return 14;
	case 'F':
		return 15;
	default:
		return -1;
	}
	return -1;
}

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		int n;
		cin >> n;
		int doublen = n * 2;
		vector<string> vcstr;
		int lines = n / 40 + 1;

		string t;
		for (int i = 0; i < lines; i++){
			cin >> t;
			vcstr.push_back(t);
		}
		string result;
		
		for (int i = 0; i < doublen;i++){
			bitset<4> countupp, countlow;
			bitset<8> count;
			int intcount = 0;
			string val;
			int pos = i / 80;
			int cu = returnVal(vcstr[pos][i%80]);			
			int tcu = cu;
			if ((i+1) / 80 > pos)
				pos++;
			int cl = returnVal(vcstr[pos][(++i) % 80]);
			
			if (cu >= 8){
				tcu -= 8;
				countupp = tcu;
				countlow = cl;
				count = tcu;
				count <<= 4;
				for (int j = 0; j < 4; j++)
					count[j] = countlow[j];

				intcount = count.to_ulong();

				if ((i + 1) / 80 > pos)
					pos++;
				val += vcstr[pos][(++i) % 80];
				if ((i + 1) / 80 > pos)
					pos++;
				val += vcstr[pos][(++i) % 80];
				


				result.append(val);
				if (cu >= 8 && intcount >= 0){
					for (int c = 0; c < intcount - 1 + 3; c++){
						result.append(val);
					}
				}
				val.clear();
			}
			else{
				countupp = tcu;
				countlow = cl;
				count = tcu;
				count <<= 4;
				for (int j = 0; j < 4; j++)
					count[j] = countlow[j];

				intcount = count.to_ulong();

				for (int j = 0; j < intcount + 1; j++){
					if ((i + 1) / 80 > pos)
						pos++;
					val += vcstr[pos][(++i) % 80];
					if ((i + 1) / 80 > pos)
						pos++;
					val += vcstr[pos][(++i) % 80];
					

					result.append(val);
					val.clear();
				}
			}
		}

		int len = result.length();
		int l = (len-1) / 80;
		cout << len / 2 << endl;
		vector<string> res(l+1);
		int p = 0;
		for (int i = 0; i < l+1; i++){
			if (i == l)
				res[i].assign(result, p, len - p);
			else
				res[i].assign(result, p, 80);
			p += 80;
		}

		int sz = res.size();
		for(int i=0;i<res.size();i++)
			cout << res[i] << endl;
	}
	return 0;
}