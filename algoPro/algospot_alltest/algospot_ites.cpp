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

const unsigned int LAST = 100 * 1000;


int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	vector<unsigned int> A(LAST);
	A[0] = 1983;
	for (int i = 1; i < LAST; i++)
	{
		A[i] = A[i - 1] * 214013u + 2531011u;
	}
	vector<long long> psum(LAST);
	psum[0] = 1983;
	for (int i = 1; i < LAST; i++)
	{
		psum[i] = psum[i - 1] + (A[i]%10000 +1);
	}

	int tc;
	cin >> tc;
	while (tc--){
		int k, n;
		cin >> k >> n;
		vector<long long> tpsum;
		int count = 0;
		long long sums = 0;
		long long past = 0;
		if (n < LAST){
			tpsum.assign(psum.begin(), psum.begin() + n);		

			for (int head = 0, tail = 0; head < n && tail < n;){
				sums = tpsum[tail] - past;

				if (sums < k)
					tail++;
				else{
					past = tpsum[head];
					head++;
					if (sums == k)
						count++;
				}
			}
		}
		else{
			vector<unsigned int> tA(A.begin(), A.end());
			tpsum = psum;

			for (int head = 0, tail = 0; head < n && tail < n;){
				sums = tpsum[tail%LAST] - past;
				
				if (sums < k)
					tail++;
				else{
					past = tpsum[head % LAST];
					if (head%LAST == 0){
						tA[0] = tA[LAST - 1] * 214013 + 2531011;
						tpsum[0] = tpsum[LAST - 1] + (tA[0] % 10000 + 1);
					}
					else{
						tA[head%LAST] = tA[(head - 1) % LAST] * 214013 + 2531011;
						tpsum[head%LAST] = tpsum[(head - 1) % LAST] + (tA[head%LAST] % 10000 + 1);
					}						
					head++;					
					if (sums == k)
						count++;
				}
			}

		}

		cout << count << endl;

	}
	return 0;
}