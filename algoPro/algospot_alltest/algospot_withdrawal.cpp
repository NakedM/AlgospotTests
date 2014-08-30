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
vector<pair<int, int > > courses;
vector<vector<double> > cache;
int N, K;


double withdrawal(int n, int k, int rank, int tot){
	if (k == K)
		return double(rank)/double(tot);
	if (n >= N)
		return 1.0;

	//cout << n << " " << k << endl;
	double& ret = cache[n][k];
	if (ret <= double(rank) / double(tot))
		return ret;

	ret = 1.0;
	for (int i = n; i < N; i++){
		ret = min(ret,withdrawal(i + 1, k + 1, rank + courses[i].first, tot + courses[i].second));
	}

	return ret;
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
		courses.clear();
		int n, k;
		cin >> n >> k;
		N = n;
		K = k;


		for (int i = 0; i < n; i++){
			int a, b;
			cin >> a >> b;
			courses.push_back(make_pair(a, b));
		}

		cache = vector<vector<double> >(n, vector<double>(k, 2.0));

		double res = withdrawal(0, 0, 0, 0);
		cout.precision(10);
		cout << fixed;
		cout << res << endl;


	}
	return 0;
}