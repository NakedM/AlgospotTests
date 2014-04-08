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
#include<functional>
using namespace std;

ifstream in("input.txt");

int main(){
#ifdef _CONSOLE    
	freopen("input.txt","r", stdin);	
	//	freopen("output.txt","w+", stdout);
#endif

	int tc;	
	cin>>tc;	
	while(tc--){
		int n,m;
		cin>>n>>m;
		vector<pair<int,int>> vt;
		vector<pair<int,int>> heapvt;
		vector<int> resvt(n,0);
		int t;
		for(int i=0;i<n;i++)
		{
			cin>>t;
			vt.push_back(make_pair(t,i));
		}
		heapvt = vt;
		make_heap(heapvt.begin(),heapvt.end(),greater<pair<int,int>>());
		int tn =n, tm = m;
		int ndm = m;
		int bnd = 0;
		while(tm > 0){
			int val = tm/tn;
			int rem = tm%tn;
			int fro = heapvt.front().first;
			if(fro == bnd)
			{
				pop_heap(heapvt.begin(),heapvt.end(),greater<pair<int,int>>());
				resvt[heapvt.back().second] = heapvt.back().first;
				ndm -=  heapvt.back().first;
				heapvt.pop_back();
				tn--;
				continue;
			}

			if(val == 0){
				vector<int> tmpvt;
				for(int i=0;i<heapvt.size();i++){
					resvt[heapvt[i].second] = bnd;
					tmpvt.push_back(heapvt[i].second);
					ndm-= bnd;
				}
				sort(tmpvt.begin(),tmpvt.end());
				for(int i=0;i<rem; i++){							
					heapvt[tmpvt[i]].first -= 1;
					resvt[tmpvt[i]] += 1;
					tm--;
					ndm--;				
				}
			}
			else{
				if(val+bnd >= fro){				
					/*for(int i=0;i<heapvt.size();i++){
					heapvt[i].first -= fro;
					resvt[heapvt[i].second] += fro;
					}*/
					int prebnd = bnd;
					bnd = fro;
					//if(val <= fro)
						tm -= (tn*(bnd-prebnd));
					/*else
						tm -= tn*fro; */
					pop_heap(heapvt.begin(),heapvt.end(),greater<pair<int,int>>());
					resvt[heapvt.back().second] = heapvt.back().first;
					ndm -=  heapvt.back().first;
					heapvt.pop_back();
					tn--;
				}
				else{
					/*for(int i=0;i<heapvt.size();i++){
					heapvt[i].first -= val;
					resvt[heapvt[i].second] += val;
					}*/
					int prebnd = bnd;
					bnd += val;
					tm -= (tn*(bnd-prebnd));
				}
			}
			if(tm == 0 && ndm > 0){
				for(int i=0;i<heapvt.size();i++){
					resvt[heapvt[i].second] = bnd;
					ndm-= bnd;
				}
			}
		}
		for(int i=0;i<resvt.size();i++){
			cout<<resvt[i];
			if(i == resvt.size()-1)
				cout<<endl;
			else 
				cout<<" ";
		}

	}	
	return 0;
}
