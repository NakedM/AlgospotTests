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

//½Ã°£ÃÊ°ú¶ä

vector<int> alphas;


void makebadchar(string& origin)
{
	int len = origin.length();
	for (int i = len - 1; i >= 0; i--)
	{
		if (origin[i] >= 'a'){
			if (alphas[origin[i] - 'a' + 26] == -1)
				alphas[origin[i] - 'a' + 26] = i;
		}
		else{
			if (alphas[origin[i] - 'A'] == -1)
				alphas[origin[i] - 'A'] = i;
		}
	}
}

int bmalgorithm(string &txt, string &pat)
{
	
	int txtlen = txt.length();
	int patlen = pat.length();
	
	int ind = patlen - 1;
	while(ind < txtlen){
		int c = 0;
		for (int j = patlen -1; j >= 0;j--)
		{			
			if (txt[ind - c] != pat[j]){
				if (txt[ind - c] >= 'a'){
					int pos = txt[ind - c] - 'a' + 26;
					if (alphas[pos] >= j){
						ind += 1;
						break;
					}
					else{
						ind = ind - c + patlen - 1 - alphas[pos];
						break;
					}
				}
				else{
					int pos = txt[ind - c] - 'A';
					if (alphas[pos] >= j){
						ind += 1;
						break;
					}
					else{
						ind = ind - c + patlen - 1 - alphas[pos];
						break;
					}
				}
			}
			if (j == 0){
				
				return ind - c;
			}
			c++;					
		}
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

	const int alphacount = 26;

	while (tc--){
		int n;
		cin >> n;
		vector<string> vc(n+1);
		for (int i = 0; i < n+1; i++)
			cin >> vc[i];

		string origin;
		origin = vc[0];		
		
		int res = 0;
		for (int i = 1; i < n+1; i++){
			if (i % 2 == 1){
				alphas = vector<int>(52, -1);
				makebadchar(origin);
				string tmp = vc[i] + vc[i];
				res += bmalgorithm(tmp, origin);
			}
			else {
				alphas = vector<int>(52, -1);
				makebadchar(vc[i]);
				string tmp = origin + origin;
				res += bmalgorithm(tmp, vc[i]);
			}
			//cout << res1 <<" "<<res2<<  endl;
			origin = vc[i];
		}
		cout <<res<< endl;
	}
	return 0;
}