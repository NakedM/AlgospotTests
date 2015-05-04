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
using namespace std;

#pragma warning (disable:4996)
ifstream in("input.txt");
vector<int> results;
map<vector<int>, int> mapp[8];
int mapind;
const int INF = 123456789;

void insertnum(vector<int>& arr,vector<bool>& nums, int ind, int n){
	if (ind >= n)
		return;
	for (int i = 1; i <= n; i++){
		if (nums[i]){
			nums[i] = false;
			arr[ind] = i;
			insertnum(arr, nums, ind + 1, n);
			nums[i] = true;
			if (ind == n - 1){
				mapp[n - 1].insert(make_pair(arr, INF));
				//mapind++;
			}
		}
	}
	return;
}

void makingvc(){
	for (int i = 1; i <= 8; i++){
		vector<int> arr(i);
		vector<bool> nums(i+1, true);
		//mapind = 0;
		insertnum(arr, nums, 0, i);
	}
}


void bfs(int n){
	//vector<int> dis(n);
	queue<vector<int> > que;
	vector<int> start(n);
	for (int i = 0; i < n; i++)
		start[i] = i + 1;

	que.push(start);
	mapp[n - 1][start] = 0;

	bool flg = false;

	while (!que.empty()){
		vector<int> here = que.front();
		que.pop();

		int currdis = mapp[n - 1][here];

		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				reverse(here.begin() + i, here.begin() + j + 1);
				//if (mapp[n - 1].count(here) == 0){
				if(mapp[n-1][here] > currdis + 1){
					que.push(here);
					mapp[n - 1][here] = currdis + 1;
					/*if (here == nvc)
						flg = true;*/

				}
				reverse(here.begin() + i, here.begin() + j + 1);
				
			}
			
		}
		//if (flg)
			//break;
	}
	return;
}

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	results = vector<int>(9, 0);
	makingvc();

	for (int i = 1; i <= 8; i++)
		bfs(i);

	while (tc--){
		int n;
		cin >> n;
		vector<int> inputarr(n);
		for (int i = 0; i < n; i++)
			cin >> inputarr[i];

		vector<int> newvc(n,1);

		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (inputarr[i] > inputarr[j])
					newvc[i]++;
			}
		}
		
		cout <<mapp[n - 1][newvc] << endl;


	}
	return 0;
}