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
//		int n, p;
//		cin>>n>>p;
//
//		vector<int> vt;
//
//		int a;
//		for(int i=0;i<n*n;i++){			
//				cin>>a;
//				vt.push_back(a);			
//		}
//
//		vector<int> contain;
//
//		int maxp = 0;
//
//		while(p!=0){
//			maxp++;
//			p/=2;
//		}
//		//maxp--;
//
//		vector<vector<int>> ex(maxp+1);
//		
//		ex[1] = vt;
//
//		for(int i=2;i<=maxp;i++){
//			long long  temp;
//			for(int j=0;j<n;j++){
//				temp=(temp+ex[i-1][j]*ex[i-1][j+n*(j)])%10007
//			}
//			ex[i].
//		}
//
//		cout<<maxp<<endl;
//
//	}
//	return 0;
//}