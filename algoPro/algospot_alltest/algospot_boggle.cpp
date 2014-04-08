//#include<iostream>
//#include<fstream>
//#include<string>
//#include<cstring>
//#include<cmath>
//#include<vector>
//#include<algorithm>
//#include<queue>
//using namespace std;
//string pan[5];
//const int dx[8] = {-1, -1, -1,  1, 1, 1, 0, 0};
//const int dy[8] = {-1,  0, 1, -1, 0, 1,-1, 1};
//bool cache[5][5][11] = {{true,true,true},};
//bool funFlg = false;
//
//ifstream in("input.txt");
//
//bool isBorder(int y, int x){
//	if(y==-1 || x==-1)
//		return true;
//	if(y==5 || x==5)
//		return true;
//	return false;
//}
//
//bool finding(int y, int x, string wordd){
//	if(funFlg) return false;
//	if(isBorder(y,x)) return false;
//	if(!cache[y][x][wordd.size()]) return false;
//	if(pan[y][x] != wordd[0]) {cache[y][x][wordd.size()] = false; return false;}
//	if(wordd.size()==1) {funFlg = true; return true;}	
//
//	for(int direc = 0; direc < 8; direc++){
//		int nextY = y+dy[direc], nextX = x+dx[direc];
//		if(finding(nextY,nextX,wordd.substr(1))){			
//			return true;
//		}
//	}
//	return false;
//}
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
//		for(int i=0;i<5;i++)cin>>pan[i];
//		int n;
//		cin>>n;
//		vector<string> strvt;
//		string str;
//		for(int i=0;i<n;i++){
//			cin>>str;
//			strvt.push_back(str);
//		}		
//	
//		for(int i=0;i<n;i++){
//			bool flg = false;
//			for(int x=0;x<5;x++){
//				for(int y=0;y<5;y++){
//					for(int s=0;s<11;s++){
//						cache[y][x][s] = true;
//					}
//				}
//			}
//			cout<<strvt[i]<<" ";
//			string strtemp = strvt[i];
//			funFlg = false;
//			for(int x=0;x<5;x++){
//				for(int y=0;y<5;y++){
//					if(pan[y][x] == strtemp[0] && !funFlg)
//						if(finding(y,x,strtemp))
//							flg = true;
//				}
//			}			
//			if(flg) cout<<"YES"<<endl;
//			else cout<<"NO"<<endl;
//		}
//
//
//	}
//	return 0;
//}