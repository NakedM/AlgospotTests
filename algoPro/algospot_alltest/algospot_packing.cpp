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

int N, capacity;
vector<int> volume, need;
vector<vector<int> > cache;
vector<string> name;

int pack(int capacity, int item)
{
	if (item == N) return 0;
	int& ret = cache[capacity][item];
	if (ret != -1)
		return ret;

	ret = pack(capacity, item + 1);

	if (capacity >= volume[item])
		ret = max(ret, pack(capacity - volume[item], item + 1) + need[item]);

	return ret;
}

void reconstruct(int capacity, int item, vector<string>& picked){
	if (item == N)
		return;

	if (pack(capacity, item) == pack(capacity, item + 1)){
		reconstruct(capacity, item + 1, picked);
	}
	else{
		picked.push_back(name[item]);
		reconstruct(capacity - volume[item], item + 1, picked);
	}
}


int main(){
	std::ios_base::sync_with_stdio(false);
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		int n, w;
		cin >> n >> w;

		N = n;
		capacity = w;

		volume = vector<int>(n, -1);
		need = vector<int>(n, -1);
		name = vector<string>(n);
		cache = vector<vector<int> >(w + 1, vector<int>(n+1, -1));
		for (int i = 0; i < n; i++){
			cin >> name[i];
			cin >> volume[i];
			cin >> need[i];
		}


		vector<string> picked;
		reconstruct(w, 0, picked);
		cout << cache[w][0] << " " << picked.size() << endl;
		for (int i = 0; i < picked.size(); i++){
			cout << picked[i] << endl;
		}


	}
	return 0;
}