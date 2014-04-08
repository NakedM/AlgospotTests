#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<cstring>
using namespace std;

vector<int> vt;

int hyun, seo;
int cache[51][51];

int ggame(int fr, int to, bool fg){
	if(to-fr == 1){
		if(fg){
			hyun = max(vt[fr],vt[to]);
			seo = min(vt[fr],vt[to]);
			return hyun - seo;
		}
		else{
			hyun = min(vt[fr],vt[to]);
			seo = max(vt[fr],vt[to]);
			return hyun - seo;
		}
	}
	if(to-fr == 0){
		if(fg){
			hyun = vt[fr]; 
			return hyun;
		}
		else{
			seo = vt[fr];
			return seo;
		}
	}
	int& ret = cache[fr][to];
	if(ret != -5000) return ret;
	ret = -3000;
	ret = max(ret, ggame(fr+2,to,!fg));
	ret = max(ret,ggame(fr,to-2,!fg));

	return ret;

}

int main(){

#ifdef _CONSOLE
	freopen("input.txt","r", stdin);
	// freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin>>tc;
	while(tc--){
		int n;
		cin>>n;
		hyun = 0;
		seo = 0;
		for(int i=0;i<51;i++){
			for(int j=0;j<51;j++){
				cache[i][j] = -5000;
			}
		}

		int a;
		for(int i=0;i<n;i++){
			cin>>a;
			vt.push_back(a);
		}

		int rst = ggame(0,n-1,1);
		cout<<rst<<endl;
		vt.clear();
	}

	return 0;
}

