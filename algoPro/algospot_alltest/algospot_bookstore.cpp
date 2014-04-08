//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//int main(){
//	
//	int tc;
//	cin>>tc;
//	vector<pair<int,int>> store[100];
//	int point[100][200];
//	int price[100][200];
//	int rst[100][2] = {{0,0},};
//
//	while(tc--){
//		int m,n;
//		cin>>n>>m;
//
//		for(int i=0;i<200;i++){
//			for(int j=0;j<100;j++){
//				point[j][i] = 0;
//				price[j][i] = 0;
//			}
//		}
//		for(int i=0;i<100;i++){
//			rst[i][0] = 0;
//			rst[i][1] = 0;
//			store[i].clear();
//		}
//
//		int pr,po;
//		for(int i=0;i<n;i++){
//			for(int j=0;j<m;j++){
//				cin>>pr>>po;
//				price[j][i] = pr;
//				point[j][i] = po;
//			}
//		}
//		int e[1];
//		for(int j=0;j<m;j++){
//			for(int i=0;i<n;i++){
//				store[j].push_back(make_pair(point[j][i],price[j][i]));
//			}
//		}
//		for(int j=0;j<m;j++){
//			sort(store[j].begin(),store[j].end());
//			reverse(store[j].begin(),store[j].end()); //큰수부터 정렬
//		}
//
//		//포인트,가격
//		for(int j=0;j<m;j++){
//			for(int i=0;i<n;i++){
//				if(rst[j][1] == 0){ // 처음 값넣음
//					rst[j][0] += store[j][i].first;
//					rst[j][1] += store[j][i].second;
//				}
//				else{
//					if(rst[j][0] >0){ //포인트가 남아있을때
//						if(store[j][i].second >=rst[j][0]){ //책값이 남아있는 포인트보다 클 때
//							rst[j][1] += (store[j][i].second - rst[j][0]);//구매가격 += 책값 - 포인트
//							rst[j][0] = store[j][i].first; //포인트 덮음.
//						}
//						else{ //책값이 남아있는 포인트보다 작을 때
//							rst[j][0] -= store[j][i].second; //포인트 - 책값
//							rst[j][0] += store[j][i].first; //포인트 더함.
//						}
//					}
//					else{//포인트가 남아있지 않을 때
//						rst[j][0] += store[j][i].first; 
//						rst[j][1] += store[j][i].second;
//					}
//				}
//			}
//		}
//
//		const int max_pr = 9999999999;
//		int rst_pr = max_pr;
//		for(int j=0;j<m;j++)
//			rst_pr = min(rst_pr,rst[j][1]);
//		
//		cout<<rst_pr<<endl;
//		
//
//
//	}
//
//	return 0;
//}