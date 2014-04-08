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
//		freopen("output.txt","w+", stdout);
//#endif
//	int tc;
//	cin>>tc;
//	while(tc--){
//		int n;
//		int rusia[101]={0,};
//		int korea[101]={0,};
//		cin>>n;
//		for(int i=0;i<n;i++)
//			cin>>rusia[i];
//		for(int i=0;i<n;i++)
//			cin>>korea[i];
//
//		sort(rusia,rusia+n);
//		sort(korea,korea+n);
//
//		int rst =  0;
//
//		int i = 0;
//		int j = 0;
//		while(1){			
//			if(korea[j] >= rusia[i]){
//				rst++;
//				j++;
//				i++;
//			}else
//				j++;
//
//			if(j>=n)
//				break;
//		}
//		cout<<rst<<endl;
//
//	}
//	return 0;
//}