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
//			reverse(store[j].begin(),store[j].end()); //ū������ ����
//		}
//
//		//����Ʈ,����
//		for(int j=0;j<m;j++){
//			for(int i=0;i<n;i++){
//				if(rst[j][1] == 0){ // ó�� ������
//					rst[j][0] += store[j][i].first;
//					rst[j][1] += store[j][i].second;
//				}
//				else{
//					if(rst[j][0] >0){ //����Ʈ�� ����������
//						if(store[j][i].second >=rst[j][0]){ //å���� �����ִ� ����Ʈ���� Ŭ ��
//							rst[j][1] += (store[j][i].second - rst[j][0]);//���Ű��� += å�� - ����Ʈ
//							rst[j][0] = store[j][i].first; //����Ʈ ����.
//						}
//						else{ //å���� �����ִ� ����Ʈ���� ���� ��
//							rst[j][0] -= store[j][i].second; //����Ʈ - å��
//							rst[j][0] += store[j][i].first; //����Ʈ ����.
//						}
//					}
//					else{//����Ʈ�� �������� ���� ��
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