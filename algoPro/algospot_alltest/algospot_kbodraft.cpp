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
//int main(){
//#ifdef _CONSOLE    
//	freopen("input.txt","r", stdin);
//	//	freopen("output.txt","w+", stdout);
//#endif
//	int tc;
//	cin>>tc;
//	while(tc--){
//		int n,k;
//		cin>>n>>k;
//		vector<pair<int,int>> vt;
//		vector<int> selected(10,0);
//		vector<int> rst;
//		int a,b;
//		for(int i=0;i<n;i++){
//			cin>>a>>b;
//			vt.push_back(make_pair(b,a));
//		}
//		
//		for(int i=0;i<n-k+1;i++){
//			selected = vector<int>(10,0);
//			for(int j=0;j<k;j++){
//				if(vt[i+j].first>selected[vt[i+j].second]){
//					selected[vt[i+j].second] = vt[i+j].first;				
//				}
//			}
//			bool flg = true;
//			for(int h=1;h<10;h++){
//				if(selected[h] <=0)
//					flg = false;
//			}
//			if(flg){
//				rst.push_back(0);
//				for(int h=1;h<10;h++){
//					rst[rst.size()-1] += selected[h];
//				}
//			}
//			selected.clear();
//		}
//
//		sort(rst.begin(),rst.end());
//
//		cout<<rst[rst.size()-1]<<endl;
//	}
//	return 0;
//}