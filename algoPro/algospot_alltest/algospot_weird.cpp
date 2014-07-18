#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include<vector>

#pragma warning (disable : 4996)

using namespace std;

const int maxx = 10000;


vector<bool> primes;
vector<bool> nums;

void checkingPrimes()
{
	primes = vector<bool>(maxx, true);

	for (int i = 4; i < maxx; i += 2)
		primes[i] = false;

	for (int i = 3; i < maxx; i++)
	{
		if (!primes[i])
			continue;
		int count = 0;
		bool flg = true;
		for (int k = 1; k < i; k+=2)
		{
			if (i % k == 0)
				++count;
			if (count > 1){
				flg = false;
				break;
			}
		}
		if (flg){
			for (int j = i + i; j < maxx; j += i)
				primes[j] = false;
		}
	}		
}

int dpWeird(int psum, int 

void checkingWeird()
{
	nums = vector<bool>(500001, false);

	int k = 4;
	int r = 0;
	int n = 0;

	int q = 0;

	while (n <= 500000)
	{
		for (int i = k+1; i < maxx; i++)
		{
			if (primes[i])
			{
				q = i;
				break;
			}
		}
		r = k*q - (q + 1);
		r = r /( (q + 1) - k);
		n = k / 2 * q * r;

		if (n > 500000)
			break;
		nums[n] = true;
		k *= 2;
	}


	vector<int> preHalf;
	vector<int> sufHalf;

	bool flg = false;
	for (int i = 70; i <= 500000; i+=2)
	{
		if (nums[i])
			continue;

		preHalf.push_back(1);
		for (int k = 2; k < i; k++){
			if (i%k == 0){
				preHalf.push_back(k);
				sufHalf.push_back(i / k);
			}
		}
		int presum = 0;
		int sufsum = 0;
		int sz = preHalf.size();
		for (int h = 0; h < sz; h++)
		{
			presum += preHalf[h];
		}

		for (int h = 0; h < sz-1; h++)
		{
			sufsum += sufHalf[h];
		}

		int totsum = presum + sufsum;

		vector<int>::iterator low;
		if (totsum > i)
		{
			int remain = totsum - i;
			low = lower_bound(preHalf.begin(), preHalf.end(), remain);
			int pos = low - preHalf.begin();


		}

		preHalf.clear();
		sufHalf.clear();
	}


}


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	
	checkingPrimes();
	checkingWeird();
	
	int tc;
	cin >> tc;

	while (tc--)
	{
		int m;
		cin >> m;

		if (nums[m])
			cout << "weird" << endl;
		else
			cout << "not weird" << endl;

	}

	return 0;
}