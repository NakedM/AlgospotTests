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
//		int cntarr[2][101] = {{0,0},};//0번째 문자, 1번째 숫자
//		vector<string> strvt;
//		string str;
//		for(int i=0;i<n;i++){
//			cin>>str;
//			strvt.push_back(str);
//		}
//		sort(strvt.begin(),strvt.end());
//
//		for(int i=0;i<n;i++){
//			for(int j=0;j<strvt[i].length();j++){
//				if(strvt[i][j] - 'a' >=0)
//					cntarr[0][i]++;
//				else
//					cntarr[1][i]++;
//			}			
//		}
//
//		double strong[101] = {0,};
//		for(int i=0;i<n;i++){
//			strong[i] = cntarr[0][i]*log10(26.0)+cntarr[1][i];
//		}
//
//		int rst = 0;
//		for(int i= 1;i<n;i++){
//			if(strong[i]>strong[rst])
//				rst = i;
//		}
//		cout<<strvt[rst]<<endl;
//
//	}
//	return 0;
//}