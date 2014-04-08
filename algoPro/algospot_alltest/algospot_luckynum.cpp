//#include<iostream>
//#include<fstream>
//#include<string>
//#include<cstring>
//#include<cmath>
//#include<vector>
//#include<algorithm>
//#include<queue>
//#include<limits>
//#include<bitset>
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
//		string str;
//		int k;
//		cin>>str;
//		cin>>k;
//		int len = str.length();
//
//		int cnt[10] = {0,};
//		int cnt2[10] = {0,};
//
//		for(int i=0;i<len;i++){
//			cnt[str[i] - '0']++;
//			cnt2[str[i] - '0']++;
//		}
//
//		string rst;
//		string rst2;
//		int kpos = cnt[k];
//
//		while(cnt[k] >0){			
//			rst+=(k+'0');
//			rst2+=(k+'0');
//			cnt[k]--;
//			cnt2[k]--;
//		}
//
//
//		bool upp = false;
//		bool dwp = false;
//		for(int i=1;i<10-k;i++){
//			if(cnt[k+i] > 0){
//				rst+=(k+i+'0');
//				upp = true;
//				cnt[k+i]--;
//				break;
//			}
//			else if(cnt[k-i] > 0){
//				rst+=(k-i+'0');
//				dwp = true;
//				cnt[k-i]--;
//				break;
//			}
//		}
//		if(upp == false && dwp ==false){
//			for(int i=2*k-10;i>=0;i--){
//				if(cnt[i] > 0){
//					rst+=(i+'0');
//					dwp = true;
//					cnt[i]--;
//					break;
//				}
//			}
//		}
//		if(upp){
//			for(int i=0;i<10;i++){
//				while(cnt[i] > 0){
//					rst+=i+'0';
//					cnt[i]--;
//				}
//			}
//		}
//		if(dwp){
//			for(int i=9;i>=0;i--){
//				while(cnt[i] > 0){
//					rst+=i+'0';
//					cnt[i]--;
//				}
//			}
//		}
//
//
//		upp = false;
//		dwp = false;
//		for(int i=1;i<10-k;i++){
//			if(cnt2[k-i] > 0){
//				rst2+=(k-i+'0');
//				dwp = true;
//				cnt2[k-i]--;
//				break;
//			}
//			else if(cnt2[k+i] > 0){
//				rst2+=(k+i+'0');
//				upp = true;
//				cnt2[k+i]--;
//				break;
//			}
//			
//		}
//		if(upp == false && dwp ==false){
//			for(int i=2*k-10;i>=0;i--){
//				if(cnt2[i] > 0){
//					rst+=(i+'0');
//					dwp = true;
//					cnt2[i]--;
//					break;
//				}
//			}
//		}
//		if(upp){
//			for(int i=0;i<10;i++){
//				while(cnt2[i] > 0){
//					rst2+=i+'0';
//					cnt2[i]--;
//				}
//			}
//		}
//		if(dwp){
//			for(int i=9;i>=0;i--){
//				while(cnt2[i] > 0){
//					rst2+=i+'0';
//					cnt2[i]--;
//				}
//			}
//		}
//
//
//		if(rst == rst2)
//			cout<<rst<<endl;
//		else{
//			int t1;
//			int t2;
//			int len = 8;
//
//
//
//
//		}
//
//		cout<<rst<<endl;
//	}
//	return 0;
//}