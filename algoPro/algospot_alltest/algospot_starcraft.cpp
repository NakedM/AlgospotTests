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
//	
//#endif
//	int tc;
//	cin>>tc;
//
//	long long facto[25];
//	facto[0] = 1;
//	facto[1] = 1;
//	for(int i=2;i<25;i++)
//		facto[i] = facto[i-1]*i;
//	while(tc--){
//		int p,k;
//		cin>>p>>k;
//
//		double win = double(p)/100.0;
//		double lose = (100-double(p))/100.0;
//		int allgame = 2*k-1;		
//
//		double rst = 0.0;
//		for(int i=k-1;i<allgame;i++){
//			double temp = 1.0;
//			long long t = facto[i]/(facto[k-1]*facto[i-(k-1)]);
//			for(int j=0;j<k;j++) temp *= win;
//			for(int h=k-1;h<i;h++) temp *= lose; 
//			rst += (temp*double(t));
//		}
//		rst*=100.0;
//		printf("%.0f\n",rst);
//	}
//	return 0;
//}