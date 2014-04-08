//#include<iostream>
//#include<fstream>
//#include<string>
//
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
//
//	while(tc--){
//		string str;
//		int arr[8];
//		cin>>str;
//
//		for(int i=0;i<7;i++)
//			arr[i+1] = str[i] - '0';
//
//		int chk1, chk2, chk3;
//		chk1 = arr[1]+arr[3]+arr[5]+arr[7];
//		chk2 = arr[2]+arr[3]+arr[6]+arr[7];
//		chk3 = arr[4]+arr[5]+arr[6]+arr[7];
//		chk1 %= 2;
//		chk2 %= 2;
//		chk3 %= 2;
//		int pos = 0;
//		pos = chk1*1+chk2*2+chk3*4;
//		if(pos != 0){
//			if(arr[pos] == 1)
//				arr[pos] = 0;
//			else
//				arr[pos] = 1;
//
//		}
//		cout<<arr[3]<<arr[5]<<arr[6]<<arr[7]<<endl;
//	}
//	return 0;
//}