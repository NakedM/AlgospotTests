//#include<iostream>
//#include<algorithm>
//
//
//using namespace std;
//
//int main(){
//
//	int tc;
//	cin>>tc;
//
//	bool chk[11][301];
//
//	while(tc--){
//
//		int a,b;
//		int count =0;
//		cin>>a>>b;
//
//		for(int i=0;i<=10;i++){
//			for(int j=0; j<=300;j++){
//				chk[i][j] = false;
//			}
//		}
//
//		chk[1][1] = true;
//
//		for(int i=2;i<=a;i++){
//			for(int j=1; j<=b;j++){
//				if(i==4)
//					chk[i/2][j*2] = true;
//				else if(i==8)
//					chk[i/4][j*3] = true;
//				else if(i==9)
//					chk[i/3][j*2] = true;
//				else
//					chk[i][j] = true;
//			}
//		}
//
//		for(int i=1;i<=10;i++){
//			for(int j=1; j<=300;j++){
//				if(chk[i][j])
//					count++;
//			}
//		}
//
//		cout<<count<<endl;
//
//	}
//}