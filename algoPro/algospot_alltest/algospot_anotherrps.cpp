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

ifstream in("input.txt");
long long three[30];

int binary(long long k){
	int ret;
	int mmin = 0;
	int mmax = 29;
	int mid = 15;
	
	for(;mmin < mmax;){
		if(three[mid] == k)
		{
			ret = mid;
			break;
		}
		if(k>three[mid])
			mmin = mid;
		else if(k < three[mid])
			mmax = mid;
		mid = (mmin + mmax)/2;
		ret = mid;
		if(mid == mmin || mid == mmax)
			break;
	}
	return ret;
}

int main(){
#ifdef _CONSOLE    
	freopen("input.txt","r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	three[0] = 3;
	for(int i=1;i<30;i++)
		three[i] = three[i-1]*3;
	string str = "RPS";
	string win = "PSR";
		
	while(1){
		long long n;
		cin>>n;
		if(n==0) break;

		
		long long count = 0;
		long long rm = 0;
		long long val = 0;
		val = n-1;
		int index = binary(val);

		while(val>=3){
			rm = val % three[index];
			val = val / three[index];
			count += val;
			val = rm;
			index--;
		}
		count += val;
		count %= 3;

		cout<<win[count]<<endl;
	}
	return 0;
}