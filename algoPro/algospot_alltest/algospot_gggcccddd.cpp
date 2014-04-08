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

vector<int> invt;
vector<vector<long long>> vt;

int main(){
#ifdef _CONSOLE    
	freopen("input.txt","r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin>>tc;
	while(tc--){
		int n,m;
		const long long MOD = 1000000007;
		cin>>n>>m;
		vt = vector<vector<long long>>(n+1);

		invt.push_back(0);
		for(int i=1;i<n+1;i++){
			int t = n/i;
			invt.push_back(t);
		}

		for(int i=0;i<m;i++)
			vt[0].push_back(1);
		
		for(int i=1;i<n+1;i++){
			vt[i].push_back(1);
			for(int j=1;j<m;j++){
				vt[i].push_back((vt[i][j-1]*i)%MOD);
			}
		}

		long long sum = n;
		for(int i=2;i<n+1;i++){
			int t = invt[n-i+1];
			if(t==1)
				sum+=n-i+1;
			else{
				for(int j=0;j<m;j++){
				
					sum = (sum+(((vt[t][m-j-1]*vt[t-1][j]))*(n-i+1))%MOD)%MOD;
					//sum = (sum+(((vt[i][m-j-1]*vt[i-1][j]))*(n-i+1))%MOD)%MOD;
				
				}
			}
			cout<<sum<<endl;
		}

		cout<<sum<<endl<<endl;
		vt.clear();
		invt.clear();
	}
	return 0;
}