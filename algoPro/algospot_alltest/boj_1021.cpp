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
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
		int n, m;
		cin >> n >> m;

		vector<int> pos(m);
		for (int i = 0; i < m; i++)
			cin >> pos[i];

		vector<int> cirQ;
		for (int i = 1; i <= n; i++)
			cirQ.push_back(i);

		int head = 0;
		int count = 0;

		int want;
		for (int i = 0; i < m; i++){
			want = pos[i]-1;
			int turnLeft =0, turnRight=0;
			int tmphead = head;
			while (tmphead != want){
				tmphead++;
				if (tmphead >= n)
					tmphead = 0;
				
				if (cirQ[tmphead] != -1)
					turnLeft++;
			}
			tmphead = head;
			while (tmphead != want){
				tmphead--;
				if (tmphead < 0)
					tmphead = n - 1;

				if (cirQ[tmphead] != -1)
					turnRight++;
			}
			count += min(turnLeft, turnRight);
			cirQ[want] = -1;
			head = want;
			while (i != m-1){
				head++;
				if (head >= n)
					head = 0;
				if (cirQ[head] != -1)
					break;
			}		
		}
	
		cout << count << endl;
	return 0;
}