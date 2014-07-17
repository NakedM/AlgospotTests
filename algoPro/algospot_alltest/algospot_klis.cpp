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

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		int n, k;
		cin >> n >> k;
		vector<int> nstr(n, 0);
		vector<int> lis(n, 1);
		

		for (int i = 0; i < n; i++)
			cin >> nstr[i];

		int maxlis = 0;
		
		int sz = nstr.size();
		for (int i = 1; i < sz; i++){
			for (int j = 0; j < i; j++){
				if (nstr[i] > nstr[j]){
					if (lis[j] >= lis[i])
						lis[i] = lis[j] + 1;
				}
			}
			maxlis = max(maxlis, lis[i]);
		}
		int lastMax;

		for (int i = sz - 1; i >= 0; i--){
			if (maxlis == lis[i]){
				lastMax = i;
				break;
			}
		}
		vector<int> order(n, -1);	//순서 가능 수 저장
		vector<int> lenMax(maxlis + 2, 1); //lis 당 최대 가능수
		order[lastMax] = 1;

		int backSum = 1;
		int curNum = lastMax;		
		int totSum = 1;	

		for (int i = lastMax - 1; i >= 0; i--){
			if (lis[i] == lis[curNum]){				
				backSum = backSum + lenMax[lis[i] + 1];
				totSum = backSum;
				curNum = i;
			}

			else if (lis[i] == lis[curNum] - 1){
				lenMax[lis[curNum]] = order[curNum];
				curNum = i;
			}
			else if (lis[i] > lis[curNum] && lis[i] == maxlis){
					backSum = 1;
					totSum += backSum;
					curNum = i;
			}
			
			order[i] = totSum;
		}

		int lastind = 0;
		for (int i = 0; i  < sz; i++){
			if (k <= order[i])
				lastind = i;
			else
				break;
		}

		vector< vector<int> > pos(maxlis + 1);
		for (int i = 0; i < sz; i++){
			if (i<lastind && lis[i] < lis[lastind])
				pos[lis[i]].push_back(i);
			else if (i>=lastind && lis[i] >= lis[lastind])
				pos[lis[i]].push_back(i);
		}
		vector<int> result;


		int dynamick = k;
		for (int j = 1; j <= maxlis; j++)
		{
			if (j < lis[lastind]){				
				result.push_back(nstr[pos[j].back()]);
			}
			else if (j == lis[lastind]){
				if(lastind == sz - 1)
					dynamick -= order[lastind ];
				else
					dynamick -= order[lastind + 1];
				result.push_back(nstr[lastind]);
			}
			else{				
				int ps = pos[j].size();
				for (int h = 0; h < ps; h++)
				{
					if (dynamick <= order[pos[j][h]])
						lastind = pos[j][h];
					else
						break;
				}
				if (lastind == sz - 1)
					dynamick -= order[lastind];
				else
					dynamick -= order[lastind + 1];
				result.push_back(nstr[lastind]);
			}
		}

		cout << maxlis << endl;
		int rssz = result.size();
		for (int i = 0; i < rssz; i++){
			cout << result[i];
			if (i != rssz - 1)
				cout << " ";
			else
				cout << endl;
		}
		
	}
	return 0;
}