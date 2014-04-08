//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main(){
//
//	int tc;
//	cin>>tc;
//	while(tc--){
//		int s;
//		cin>>s;
//
//		int vt[202][101] = {{0,0},};
//		int rst[202][101] = {{0,0},};
//		int t;
//		for(int i=0;i<s;i++){
//			for(int j=0;j<=i;j++){
//				cin>>t;
//				vt[i][j]= t;
//			}			
//		}
//		for(int i=s;i<2*s-1;i++){
//			for(int j=0;j<=(2*s-1)-i-1;j++){
//				cin>>t;
//				vt[i][j]= t;
//			}			
//		}
//
//		rst[0][0] =vt[0][0]; 
//
//		for(int i=1;i<s;i++){
//			for(int j=0;j<s;j++){
//				if(j==0){
//					rst[i][j] = (vt[i][j]+rst[i-1][j]);
//				}
//				if(j>=1){
//					rst[i][j] = vt[i][j]+max(rst[i-1][j],rst[i-1][j-1]);
//				}
//			}
//		}
//		for(int i=s;i<2*s-1;i++){
//			for(int j=0;j<s;j++){
//				if(j>=0){
//					rst[i][j] = vt[i][j]+max(rst[i-1][j],rst[i-1][j+1]);
//				}
//			}
//		}
//
//		//sort(rst[s-1],rst[s-1]+s);
//
//		cout<<rst[2*s-2][0]<<endl;
//
//
//	}
//
//	return 0;
//}