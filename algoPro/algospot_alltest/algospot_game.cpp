//#include<iostream>
//#include<fstream>
//#include<string>
//#include<cstring>
//#include<cmath>
//#include<vector>
//#include<algorithm>
//#include<queue>
//using namespace std;
//
//ifstream in("input.txt");
//
//int main(){
//#ifdef _CONSOLE    
//	freopen("input.txt","r", stdin);
//		freopen("output.txt","w+", stdout);
//#endif
//	int tc;
//	cin>>tc;
//	while(tc--){
//		int n, k;
//		cin>>n>>k;
//
//		vector<bool> winer(n+1,false);
//		vector<vector<int>> vt(n+1);
//		int a;
//		for(int i=1;i<n+1;i++){
//			for(int j=0;j<k;j++){
//				cin>>a;
//				vt[i].push_back(a);
//			}
//		}	
//		vector<pair<int,int>> temp;
//		for(int i=0;i<k;i++){
//			bool flg = false;
//			for(int j=1;j<n+1;j++){
//				if(!winer[j])
//					temp.push_back(make_pair(vt[j][i],j));
//			}
//			sort(temp.begin(),temp.end());
//			if(temp[0].first != temp[1].first){
//				winer[temp[0].second] = true;
//				temp.clear();
//				continue;
//			}
//			else{
//				flg = true;
//				for(int h=1;h<temp.size();h++){
//					winer[temp[0].second] = false;
//					if(temp[0].first != temp[h].first)
//						winer[temp[h].second] = true;
//					else
//						winer[temp[h].second] = false;
//				}
//			}
//			if(flg)
//				break;
//		}
//		
//		int cnt = 0;
//		for(int i=1;i<winer.size();i++){
//			if(!winer[i]){				
//				if(cnt != 0){
//					cout<<" ";					
//				}
//				cnt++;
//				cout<<i;
//			}					
//		}
//		cout<<endl;
//		
//	}
//	return 0;
//}