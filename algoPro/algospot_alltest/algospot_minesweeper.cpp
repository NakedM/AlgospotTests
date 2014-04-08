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
//const int movey[8] = {1,1,0,-1,-1,-1,0,1};
//const int movex[8] = {0,1,1,1,0,-1,-1,-1};
//vector<vector<int>> vt;
//vector<pair<int,int>> minee;
//vector<vector<bool>> bvt;
//int r,c;
//
//void sweep(int fy, int fx){
//	if(!bvt[fy][fx]) return;
//	
//	bvt[fy][fx] = false;
//
//	for(int h=0;h<8;h++){
//			int ny = fy+movey[h];
//			int nx = fx+movex[h];
//			if(ny >= 0 && nx >=0 && ny < r && nx <c){
//				if(vt[ny][nx] == 0 && bvt[ny][nx]){
//					sweep(ny,nx);
//				}
//			}
//	}
//
//	return;
//}
//
//int main(){
//#ifdef _CONSOLE    
//	freopen("input.txt","r", stdin);
//	//	freopen("output.txt","w+", stdout);
//#endif
//	int tc;
//	cin>>tc;
//	while(tc--){
//		
//		cin>>r>>c;
//
//		vt = vector<vector<int>>(r);
//		bvt = vector<vector<bool>>(r);
//
//		
//		char t;
//		for(int i=0;i<r;i++){
//			for(int j=0;j<c;j++){
//					cin>>t;
//					if(t=='.'){
//						vt[i].push_back(0);
//						bvt[i].push_back(true);
//					}
//					if(t=='*'){
//						vt[i].push_back(-1);
//						minee.push_back(make_pair(i,j));
//						bvt[i].push_back(false);
//					}
//			}
//		}
//
//		for(int i=0;i<minee.size();i++){
//			for(int j=0;j<8;j++){
//				int ny = minee[i].first+movey[j];
//				int nx = minee[i].second+movex[j];
//				if(ny >= 0 && nx >=0 && ny < r && nx <c)
//					if(vt[ny][nx] != -1)
//						vt[ny][nx] = 1;
//			}
//		}
//
//		for(int i=0;i<r;i++){
//			for(int j=0;j<c;j++){
//				if(vt[i][j] == 0){
//					for(int h=0;h<8;h++){
//						int ny = i+movey[h];
//						int nx = j +movex[h];
//						if(ny >= 0 && nx >=0 && ny < r && nx <c){
//							if(vt[ny][nx] == 1){
//								vt[ny][nx] = 2;
//								bvt[ny][nx] = false;
//							}
//						}
//					}
//				}			
//				
//			}
//		}
//
//		int rst = 0;
//		for(int i=0;i<r;i++){
//			for(int j=0;j<c;j++){
//				if(vt[i][j] == 1){
//					rst++;
//					bvt[i][j] = false;
//				}
//				if(vt[i][j] == 0 && bvt[i][j]){
//					sweep(i,j);
//					rst++;
//				}
//			}			
//		}
//
//		cout<<rst<<endl;
//
//		vt.clear();
//		minee.clear();
//	}
//	return 0;
//}