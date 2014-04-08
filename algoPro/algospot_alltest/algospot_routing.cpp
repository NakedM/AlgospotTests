//#include<iostream>
//#include<fstream>
//#include<string>
//#include<cstring>
//#include<cmath>
//#include<vector>
//#include<algorithm>
//#include<queue>
//#include<limits>
//using namespace std;
//
//ifstream in("input.txt");
//
//const long double INF = numeric_limits<long double>::max();
//
//int main(){
//#ifdef _CONSOLE    
//	freopen("input.txt","r", stdin);
////		freopen("output.txt","w+", stdout);
//#endif
//	int tc;
//	cin>>tc;
//	while(tc--){
//		int n, line;
//		cin>>n>>line;
//
//		vector<vector<pair<long double,int>>> vt(n);
//		vector<pair<long double,int>> minpvt;
//		vector<long double> noise(n,INF);
//		priority_queue<pair<long double,int>,vector<pair<long double,int>>,greater<pair<long double,int>>> pq;
//
//		int a,b;
//		long double c;
//		for(int i=0;i<line;i++){
//			cin>>a>>b;
//			cin>>c;
//			vt[a].push_back(make_pair(c,b));
//			vt[b].push_back(make_pair(c,a));
//		}
//
//		noise[0] = 1.0;
//		pq.push(make_pair(1.0,0));
//
//		
//		while(!pq.empty()){			
//			long double bump = pq.top().first;
//			int here = pq.top().second;
//
//			pq.pop();
//
//			if(noise[here] < bump) continue;
//
//			for(int i=0;i<vt[here].size();i++){
//				long double nextBump = bump*vt[here][i].first;
//				int there = vt[here][i].second;
//
//				if(noise[there] > nextBump){
//					noise[there] = nextBump;
//					pq.push(make_pair(nextBump,there));
//				}
//			}
//		}
//		cout.precision(10);
//		cout<<fixed<<noise[n-1]<<endl;
//		//printf("%.10f\n",noise[n-1]);
//	}
//	return 0;
//}
////make_heap(minpvt.begin(),minpvt.end(),greater<pair<long double,int>>());
////		minpvt.push_back(make_pair(1.0,0));
//		/*for(int i=0;i<vt[0].size();i++){
//			minpvt.push_back(vt[0][i]);
//			push_heap(minpvt.begin(),minpvt.end(),greater<pair<long double,int>>());
//		}
//	*/
//
///*long double bump = minpvt.front().first;
//			int here = minpvt.front().second;
//
//			pop_heap(minpvt.begin(),minpvt.end(),greater<pair<long double,int>>());
//			minpvt.pop_back();
//
//			if(noise[here] < bump) continue;
//
//			for(int i=0;i<vt[here].size();i++){
//				int there = vt[here][i].second;
//				long double nextBump = bump*vt[here][i].first;
//
//				if(noise[there] > nextBump){
//					noise[there] = nextBump;
//					minpvt.push_back(make_pair(nextBump,there));
//					push_heap(minpvt.begin(),minpvt.end(),greater<pair<long double,int>>());
//				}
//			}*/