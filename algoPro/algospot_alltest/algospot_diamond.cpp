//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int n;
//char grd[55][55];
//int d =0 ;
//
//int cal(int depth){
//	if(depth >=n)
//		return 0;
//	d=depth;
//	for(int i=0;i<n;i++){
//			for(int j=0;j<n;j++){
//				if(grd[i][j] == '#'&& grd[i+2][j]) cal(depth+2);
//
//		}
//	}
//
//	return 0;
//}
//
//int main(){
//
//	int tc;
//	cin>>tc;
//	while(tc--){
//		for(int i=0;i<n;i++)
//			for(int j=0;j<n;j++)
//				grd[i][j] = '\0';
//
//		cin>>n;
//		for(int i=0;i<n;i++)
//			for(int j=0;j<n;j++)
//				cin>>grd[i][j];
//		
//		int rst = 0;
//		cal(1);
//		
//
//
//
//	}
//
//	return 0;
//}