//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int main(){
//
//	int tc;
//	cin>>tc;
//
//	while(tc--){
//
//		int cntx[2][2] = {{0,0},};
//		int cnty[2][2] = {{0,0},};
//
//		int a,b;
//
//		for(int j=0;j<3;j++){
//			cin>>a>>b;
//			
//				if(j==0){
//					cntx[0][0] = a;
//					cnty[0][0] = b;
//				}
//				else{
//					if(cntx[0][0] != a)
//						cntx[1][0] = a;
//					if(cnty[0][0] !=b)
//						cnty[1][0] = b;
//				}
//				for(int i =0;i<2;i++){
//					if(cntx[i][0] == a)
//						cntx[i][1]++;
//					if(cnty[i][0] == b)
//						cnty[i][1]++;
//				}
//			
//		}
//
//		int rstx = 0, rsty = 0;
//		for(int h =0;h<2;h++){
//			if(cntx[h][1] % 2 != 0){
//				rstx = cntx[h][0];
//			}
//			if(cnty[h][1] % 2 != 0){
//				rsty = cnty[h][0];
//			}
//		}
//
//		cout<<rstx<<" "<<rsty<<endl;
//
//
//		
//
//
//
//	}
//
//
//	return 0;
//}