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

int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		int n;
		cin >> n;
		string str;
		cin >> str;
		int p, q;
		cin >> p >> q;
		int left = 0, right = str.length() - 1;
		int result = 0;

		while (left < right){
			if (str[left] == '?' && str[right] == '?'){
				result += (min(p, q) * 2);
			}
			else if (str[left] == '?' && str[right] != '?'){
				if (str[right] == 'a')
					result += p;
				else
					result += q;
			}
			else if (str[left] != '?' && str[right] == '?'){
				if (str[left] == 'a')
					result += p;
				else
					result += q;
			}
			left++;
			right--;
		}

		if (left == right && str[left] == '?')
			result += min(p, q);

		cout << result << endl;


	}
	return 0;
}