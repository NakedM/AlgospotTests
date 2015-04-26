#include<iostream>
#include<cstdio>
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

int vc2[1000001];
int vc1[1000001];

bool bs(int start, int end, int val){
	if (start > end || end < 0)
		return false;

	int mid = (start + end) / 2;
	if (vc1[mid] == val)
		return true;
	else if (val > vc1[mid])
		return bs(mid+1, end, val);
	else
		return bs(start, mid-1, val);

}

int main(){	
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
#endif
	int tc;
	scanf("%d", &tc);
	while (tc--){
		int n, m;
		scanf("%d",&n);
		
		//vector<int> vc1(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &vc1[i]);		
		//sort(vc1.begin(), vc1.end());
		sort(vc1, vc1 + n);
		scanf("%d", &m);
		//int a;
		for (int i = 0; i < m; ++i){
			cin >> vc2[i];
		}
		for (int i = 0; i < m; ++i){
			//cin >> a;
			//if (binary_search(vc1.begin(), vc1.end(), a))
			if (bs(0, n-1, vc2[i]))
				printf("1\n");
			else
				printf("0\n");
		}

		

	}
	return 0;
}