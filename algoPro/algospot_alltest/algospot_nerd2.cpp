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
#include<iterator>
using namespace std;

#pragma warning (disable:4996)
ifstream in("input.txt");

map<int, int> binarytree;
void removes(int p, int q)
{
	map<int, int>::iterator it;
	it = binarytree.lower_bound(p);

	if (it != binarytree.begin()){
		it--;
		while (true){
			int smallq = it->second;
			if (smallq > q)
				break;

			if (it == binarytree.begin()){
				binarytree.erase(it);
				break;
			}
			else{
				map<int, int>::iterator nt = it;
				nt--;
				binarytree.erase(it);
				it = nt;
			}
		}
	}
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
		int p, q;
		
		//int count = 0;
		long long sum = 0;
		cin >> n;
		cin >> p >> q;

		
		binarytree.insert(make_pair(p,q));
		sum += 1;
		
		for (int nerd = 1; nerd < n; nerd++){
			cin >> p >> q;
			map<int, int>::iterator it;
			
			it = binarytree.lower_bound(p);
			if (it != binarytree.end()){
				int biggerq = it->second;
				if (q > biggerq )
				{
					removes(p, q);
					binarytree.insert(make_pair(p, q));
				}
			}
			else
			{
				removes(p, q);
				binarytree.insert(make_pair(p, q));
			}			
			sum += binarytree.size();
		}
		cout << sum << endl;
		binarytree.clear();
	}
	return 0;
}