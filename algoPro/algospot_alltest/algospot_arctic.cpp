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
//		int n;
//		cin>>n;
//		vector<double> minval(n,123456789);
//		vector<double> pos[2];
//		double a,b;
//		for(int i=0;i<n;i++){
//			cin>>a>>b;
//			pos[0].push_back(a);//x
//			pos[1].push_back(b);//y
//		}
//		double pan[101][101]={0.0,};
//		vector<double> vt;
//		for(int i=0;i<n;i++){
//			for(int j=0;j<n;j++){
//				if(i==j)
//					continue;
//				double c = abs(pos[0][i] - pos[0][j]);
//				double d = abs(pos[1][i] - pos[1][j]);
//				pan[i][j] = c*c+d*d;
//				//minval[j] = min((c*c+d*d),minval[j]);
//			}
//			sort(pan[i],pan[i]+n);
//			double dist = 0.0;
//			for(int j=1;j<n;j++){
//				if(pan[i][j]-pan[i][j-1] > dist)
//					dist = pan[i][j];
//			}
//			vt.push_back(dist);
//		}
//
//		double rst = sqrt(*max_element(minval.begin(),minval.end()));
//		printf("%.2f\n",rst);
//
//	}
//	return 0;
//}4