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
//	string y1[18] = {"20","21","22","23","24","25","30","31","32","33","34","35","40","41","42","43","44","45"};
//	string y2[60] = {"00","01","02","03","04","05","10","11","12","13","14","15",
//					"20","21","22","23","24","25","30","31","32","33","34","35",
//					"40","41","42","43","44","45","50","51","52","53","54","55",
//					"60","61","62","63","64","65","70","71","72","73","74","75",
//					"80","81","82","83","84","85","90","91","92","93","94","95"};
//	string mon[5] = {"01","02","10","11","12"};
//	string dday[2] ={"11","22"};
//	vector<string> vt;
//	int ssize =0;
//	while(ssize<10000){
//		for(int i = 0;i<18;i++){
//			for(int j=0;j<60;j++){
//				for(int h=0;h<5;h++){
//					for(int k=0;k<2;k++){
//						string str = y1[i]+y2[j]+mon[h]+dday[k];
//						for(int m = 1;m>=0;m--) str+=mon[h][m];
//						for(int m = 1;m>=0;m--) str+=y2[j][m];
//						for(int m = 1;m>=0;m--) str+=y1[i][m];
//
//						vt.push_back(str);
//						ssize++;
//					}
//				}
//			}
//		}
//	}
//	while(tc--){
//		int n;
//		cin>>n;
//				
//		//for(int k=0;k<n;k++){
//			for(int i=0;i<14;i++){
//				cout<<vt[n-1][i];
//				if(i==3 || i==5)
//					cout<<"-";
//				if(i==7)
//					cout<<" ";
//				if(i==9 || i==11)
//					cout<<":";
//			}
//			cout<<endl;
//		//}
//	}
//	return 0;
//}