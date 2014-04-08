//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<list>
//using namespace std;
//
//
//
//int main(){
//
//	int tc;
//	cin>>tc;
//
//	while(tc--){
//
//		int n,m;
//		cin>>n>>m;
//  
//		vector<vector<pair<int,int>>> vt(n);
//		vector<pair<int,int>> pvt;
//		vector<int> valvt(n,123456789);
//	 
//		int a,b,c;
//		for(int i=0;i<m;i++){
//			cin>>a>>b>>c;
//			vt[a].push_back(make_pair(c,b));
//			vt[b].push_back(make_pair(c,a));   
//		}
//
//		valvt[0] = 0;
//		
//		make_heap(pvt.begin(),pvt.end(), greater<pair<int,int>>());
//		for(int i=0;i<vt[0].size();i++){
//			pvt.push_back(vt[0][i]);
//			push_heap(pvt.begin(),pvt.end(), greater<pair<int,int>>());
//		}
//
//		while(!pvt.empty()){
//
//			int cost = pvt.front().first;
//			int here = pvt.front().second;	
//			  
//			pop_heap(pvt.begin(),pvt.end(), greater<pair<int,int>>());
//			pvt.pop_back();
//
//			if(valvt[here] < cost) continue;
//
//			for(int i=0;i<vt[here].size();i++){
//				int there = vt[here][i].second;
//				int nextDist = cost+ vt[here][i].first;
//
//				if(valvt[there]> nextDist){
//					valvt[there] = nextDist;
//					pvt.push_back(make_pair(nextDist,there));
//					push_heap(pvt.begin(),pvt.end(), greater<pair<int,int>>());
//				}
//			}
//		}
//
//		cout<<valvt[n-1]<<endl;
//	}
//	return 0;
//}
//
