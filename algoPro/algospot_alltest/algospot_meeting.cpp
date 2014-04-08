//#include<iostream>
//#include<fstream>
//#include<string>
//#include<cstring>
//#include<cmath>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//ifstream in("input.txt");
//
//int main(){
//#ifdef _CONSOLE    
//	freopen("input.txt","r", stdin);
//	//	freopen("output.txt","w+", stdout);
//#endif
//
//	int tc;
//	cin>>tc;
//	while(tc--){
//		int n;
//		cin>>n;
//		int male[10001] = {0,};
//		int female[10001]= {0,};
//
//		int man = 0;
//		int wom = 0;
//
//		for(int i=0;i<n;i++){
//			cin>>male[i];			
//		}
//		for(int i=0;i<n;i++){
//			cin>>female[i];			
//		}
//
//		sort(male,male+n);
//		sort(female,female+n);
//
//		//int rst[10001] = {0,};
//		int sum = 0;
//
//		for(int i=0;i<n;i++){
//			sum += abs(male[i] - female[i]);
//		}
//		cout<<sum<<endl;
//	}
//	return 0;
//}
