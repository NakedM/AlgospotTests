//#include<iostream>
//#include<fstream>
//#include<string>
//#include<cstring>
//#include<cmath>
//#include<vector>
//#include<algorithm>
//#include<queue>
//#include<limits>
//#include<bitset>
//using namespace std;
//
//ifstream in("input.txt");
//
//const int movey[8] = {1,1,0,-1-1,-1,0,1};
//const int movex[8] = {0,1,1,1,0,-1,-1,-1};
//
//int r,c;
//vector<vector<long long>> vt;
//vector<vector<bool>> bvt;
//
//void movechk(int my, int mx, int v){
//	if(vt[my][mx] == v)
//		bvt[my][mx] = false;
//	else
//		return;
//
//	for(int h=0;h<8;h++){
//		if((my+movey[h] < r) && (mx+movex[h] < c) && (my+movey[h] >= 0) && (mx+movex[h] >=0))
//			if(bvt[my+movey[h]][mx+movex[h]])
//				movechk(my+movey[h],mx+movex[h],v);
//	}
//	return;
//}
//
//int main(){
//#ifdef _CONSOLE    
//	freopen("input.txt","r", stdin);
//	//	freopen("output.txt","w+", stdout);
//#endif
//	while(1){
//		
//		cin>>r>>c;
//		if(r==0 && c==0)
//			break;
//		
//		
//		vt = vector<vector<long long>>(r);
//		bvt = vector<vector<bool>>(r);
//
//		for(int i=0;i<r;i++){
//			vt[i] = vector<long long>(c,0);
//			bvt[i] = vector<bool>(c,true);
//		}
//
//		int n;
//		cin>>n;
//		vector<vector<pair<int,int>>> pos(n);
//		
//		for(int i=0;i<n;i++){			
//				int t1,t2,t3,t4;
//				cin>>t1>>t2>>t3>>t4;
//
//				pos[i].push_back(make_pair(min(t1,t3),min(t2,t4)));
//				pos[i].push_back(make_pair(max(t1,t3)-1,max(t2,t4)-1));
//
//				if(t1==t3)
//					pos[i][1].first +=1;
//				if(t2==t4)
//					pos[i][1].second +=1;
//		}
//
//		long long val = 1;
//		for(int i=0;i<n;i++){
//			val<<=1;
//			for(int x = pos[i][0].first; x<=pos[i][1].first;x++){
//				for(int y = pos[i][0].second; y<=pos[i][1].second;y++){
//					vt[y][x] += val;
//				}
//			}
//		}
//
//		int rst=0;
//		for(int i=0;i<r;i++){
//			for(int j=0;j<c;j++){
//				if(bvt[i][j]){
//					movechk(i,j,vt[i][j]);
//					rst++;
//				}
//			}
//		}
//
//
//		cout<<rst<<endl;
//		vt.clear();
//		bvt.clear();
//
//
//	}
//	return 0;
//}