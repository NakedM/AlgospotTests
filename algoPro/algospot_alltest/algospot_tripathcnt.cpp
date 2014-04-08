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
//	//	freopen("output.txt","w+", stdout);
//#endif
//	int tc;
//	cin>>tc;
//	while(tc--){
//
//		int s;
//		cin>>s;
//
//		int vt[101][101] = {{0,0},};
//		int rst[101][101] = {{0,0},};
//		int cnt[101][101] = {{0,0},};
//		
//		for(int i=0;i<s;i++){
//			for(int j=0;j<=i;j++){
//				cin>>vt[i][j];
//			}			
//		}
//
//		rst[0][0] =vt[0][0];
//		cnt[0][0] = 1;
//		for(int i=1;i<s;i++){
//			for(int j=0;j<s;j++){
//				if(j==0){
//					rst[i][j] = (vt[i][j]+rst[i-1][j]);
//					cnt[i][j] = 1;
//				}
//				if(j>=1){
//					int t;
//					rst[i][j] = vt[i][j];
//					if(rst[i-1][j]>rst[i-1][j-1]){
//						rst[i][j] += rst[i-1][j];
//						cnt[i][j] = cnt[i-1][j]; 
//					}
//					else if(rst[i-1][j]==rst[i-1][j-1]){
//						rst[i][j] += rst[i-1][j];
//						cnt[i][j] = cnt[i-1][j]+cnt[i-1][j-1];
//					}
//					else{
//						rst[i][j] += rst[i-1][j-1];
//						cnt[i][j] = cnt[i-1][j-1];
//					}						
//				}
//			}
//		}
//
//		int sum = 0;
//		int mmax = *max_element(rst[s-1],rst[s-1]+s);
//
//
//		for(int i=0;i<s;i++){
//			if(mmax==rst[s-1][i])
//				sum+=cnt[s-1][i];
//		}
//		cout<<sum<<endl;
//	}
//	return 0;
//}