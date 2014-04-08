//#include<iostream>
//#include<algorithm>
//#include<cmath>
//
//using namespace std;
//
//int main(){
//	int tCase = 0;
//	cin>>tCase;
//	while(tCase--){
//		int N = 0;
//		cin>>N;
//		int arr[500] = {0};
//		int brr[500];
//		int rst = 1;
//
//		for(int i = 0; i<N; i++){
//			cin>>arr[i];
//		}
//		for(int i = 0; i<N; i++){
//			brr[i] = 1;
//		}
//
//		for(int i = 1; i<N; i++){			
//			for(int j = 0; j <i; j++){
//				if(arr[j]<arr[i])
//				{
//					if(brr[j] >= brr[i])
//						brr[i] = brr[j]+1;					
//				}
//			}
//			rst = max(brr[i],rst);
//		}
//
//		cout<<rst<<endl;			
//	}
//	return 0;
//}