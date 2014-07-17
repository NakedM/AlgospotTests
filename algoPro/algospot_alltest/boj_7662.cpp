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
#include<functional>
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
		vector<bool> pushed(1000000, false);

		vector<pair<int,int> > maxpq;
		vector<pair<int,int> > minpq;		

		make_heap(maxpq.begin(),maxpq.end(),less<pair<int,int> >());
		make_heap(minpq.begin(), minpq.end(), greater<pair<int,int> >());

		int n;
		cin >> n;

		string op;
		int val;
		int ind = 0;
		for (int i = 0; i < n; i++){
			cin >> op >> val;
			if (op[0] == 'I')
			{
				pushed[ind] = true;
				maxpq.push_back(make_pair(val, ind));
				push_heap(maxpq.begin(), maxpq.end(), less<pair<int, int> >());
				minpq.push_back(make_pair(val, ind++));
				push_heap(minpq.begin(), minpq.end(), greater<pair<int, int> >());
			}
			else{
				if (val == 1){
					if (!maxpq.empty()){
						while (!pushed[maxpq.front().second]){
							pop_heap(maxpq.begin(), maxpq.end(), less<pair<int, int> >());
							maxpq.pop_back();

							if (maxpq.empty())
								break;
						}
						if (!maxpq.empty()){
							pop_heap(maxpq.begin(), maxpq.end(), less<pair<int, int> >());
							int tmpind = maxpq.back().second;
							pushed[tmpind] = false;
							maxpq.pop_back();
						}
					}
				}
				else if (val == -1){
					if (!minpq.empty()){
						while (!pushed[minpq.front().second]){
							pop_heap(minpq.begin(), minpq.end(), greater<pair<int, int> >());
							minpq.pop_back();
							if (minpq.empty())
								break;
						}
						if (!minpq.empty()){
							pop_heap(minpq.begin(), minpq.end(), greater<pair<int, int> >());
							int tmpind = minpq.back().second;
							pushed[tmpind] = false;
							minpq.pop_back();
						}
					}
				}
			}
		}
		if (!maxpq.empty()){
			while (!pushed[maxpq.front().second]){
				pop_heap(maxpq.begin(), maxpq.end(), less_equal<pair<int, int> >());
				maxpq.pop_back();

				if (maxpq.empty())
					break;
			}
		}
		if (!minpq.empty()){
			while (!pushed[minpq.front().second]){
				pop_heap(minpq.begin(), minpq.end(), greater_equal<pair<int, int> >());
				minpq.pop_back();
				if (minpq.empty())
					break;
			}
		}

		if (maxpq.empty() || minpq.empty())
			cout << "EMPTY" << endl;
		else
			cout << maxpq.front().first << " "
			<< minpq.front().first << endl;
	}
	return 0;
}