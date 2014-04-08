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

long long comb(int x, int y){ //x>y
	long long ch=1;
	long long pa=1;

	if(y!= 0 && x!=y)
	{
		for(int i=y+1;i<=x;i++)
			ch*=i;
		for(int j=1;j<=(x-y);j++)
			pa*=j;
	}

	long long ret = ch/pa;

	return ret;
}
int main(){
#ifdef _CONSOLE    
	freopen("input.txt","r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin>>tc;
	while(tc--){
		int ax, ay, bx, by;
		cin>>ax>>ay>>bx>>by;

		long long rst;
		int distx = bx-ax, disty = by-ay;
		int absx = abs(distx), absy(disty);

		if((distx >= 0 && disty >= 0) || (distx <=0 && disty <=0)){
			if(absx >= absy)
				rst = comb(absx+absy,absx);
			else
				rst = comb(absx+absy,absy);
		}
		else
		{
			if(absx >= absy)
				rst = comb(absx+absy-1,absx-1);
			else
				rst = comb(absx+absy-1,absy-1);
		}
		cout<<rst<<endl;
	}
	return 0;
}