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

const int INF = 987654321;

#pragma warning (disable:4996)
ifstream in("input.txt");
long long n, m, k;

bool sequ(int index, int remain, int last, int& count, vector<int> vc){
	if (index == n){
		count++;
		if (count == k){
			for(int i=0;i<vc.size();i++)
				cout << vc[i]<<" ";
			cout << endl;
			return true;
		}
		return false;
	}
	if (index == n - 1){
		if (last > remain)
			return false;
		vc.push_back(remain);
		if (sequ(index + 1, remain, remain, count, vc))
			return true;
		else
			vc.pop_back();
	}
	else{
		for (int i = last; i < remain + 1; i++){	
			vc.push_back(i);
			if (sequ(index + 1, remain - i, i, count, vc))
				return true;
			else
				vc.pop_back();
		}
	}

	return false;
}

int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
#endif	
	cin >> n >> m >> k;
	int count = 0;
	vector<int> vc;
	sequ(0, m, 1, count, vc);

	return 0;
}