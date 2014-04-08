//#include<iostream>
//#include<fstream>
//#include<string>
//#include<cstring>
//using namespace std;
//
//ifstream in("input.txt");
//
//int arr[100][100];
//bool brr[100][100];
//
//void jumpg(int py, int px, int n){
//	if(py >=n || px>=n)
//		return;	
//	if(brr[py][px])
//		return;
//	brr[py][px] = true;
//	if(px==n-1 && py== n-1)
//		return;	
//	jumpg(py+arr[py][px],px,n);
//	jumpg(py,px+arr[py][px],n);
//}
//
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
//		
//		for(int i=0;i<100;i++){
//			memset(arr[i],0,100);
//			memset(brr[i],false,100);
//		}
//
//		int t;
//		for(int i=0;i<n;i++){
//			for(int j=0;j<n;j++){
//				cin>>arr[i][j];
//			}
//		}
//
//		jumpg(0,0,n);
//
//		if(brr[n-1][n-1])
//			cout<<"YES"<<endl;
//		else
//			cout<<"NO"<<endl;
//
//	}
//	return 0;
//}