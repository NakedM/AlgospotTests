//#include<iostream>
//#include<fstream>
//#include<string>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//ifstream in("input.txt");
//
//int main(){
//#ifdef _CONSOLE    
//	freopen("input.txt","r", stdin);
//	//	freopen("output.txt","w+", stdout);
//#endif
//	int tc;
//	cin>>tc;
//	int tcc	= tc;
//
//	while(tc--){
//		int pan[25][25] = {{0,0},};
//		int n;
//		cin>>n;
//		for(int i=1;i<n+1;i++){
//			for(int j=1;j<n+1;j++){
//				cin>>pan[i][j];
//			}
//		}
//		vector<int> vt[4];
//		bool flg = false;
//		int sum=0;
//		for(int i=2;i<n+1;i++){
//			flg = false;
//			for(int j=1;j<n+1;j++){
//				if(pan[i][j]!=0 && !flg){
//					flg = true;
//					vt[0].push_back(i);
//					vt[1].push_back(j-1);
//					vt[2].push_back(0);
//					vt[3].push_back(pan[i][j]);
//				}
//				else if(pan[i][j]!=0 && flg){
//					vt[3][vt[3].size()-1]+=pan[i][j];
//
//				}
//				else if(pan[i][j] == 0)
//					flg = false;
//			}
//		}
//
//		vector<pair<int,int>> pvt;
//		vector<int> vvt[4];
//		
//		for(int j=2;j<n+1;j++){
//			flg = false;
//			for(int i=1;i<n+1;i++){
//				if(pan[i][j]!=0 && !flg){
//					flg = true;
//					pvt.push_back(make_pair(i,vvt[0].size()));
//					vvt[0].push_back(i-1);
//					vvt[1].push_back(j);
//					vvt[2].push_back(1);
//					vvt[3].push_back(pan[i][j]);
//				}
//				else if(pan[i][j]!=0 && flg){
//					vvt[3][vvt[3].size()-1]+=pan[i][j];
//
//				}
//				else if(pan[i][j] == 0)
//					flg = false;
//			}
//		}
//
//		sort(pvt.begin(),pvt.end());
//
//		cout<<tcc<<endl<<n<<endl;
//		for(int i=1;i<n+1;i++){
//			for(int j=1;j<n+1;j++){
//				if(pan[i][j] != 0)
//					cout<<1;
//				else
//					cout<<0;
//				if(j!=n)
//					cout<<" ";
//			}
//			cout<<endl;
//		}
//		cout<<vt[1].size()+vvt[1].size()<<endl;
//		for(int i=0;i<vt[0].size();i++)
//			cout<<vt[0][i]<<" "<<vt[1][i]<<" "<<vt[2][i]<<" "<<vt[3][i]<<endl;
//		for(int i=0;i<vvt[0].size();i++)
//			cout<<vvt[0][pvt[i].second]<<" "<<vvt[1][pvt[i].second]<<" "<<vvt[2][pvt[i].second]<<" "<<vvt[3][pvt[i].second]<<endl;
//		
//	}
//	return 0;
//}