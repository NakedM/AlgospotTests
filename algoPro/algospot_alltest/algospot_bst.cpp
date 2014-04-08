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
//vector<int> tr[3];
//vector<bool> visited;
//
//void binaryT(int ind, char c, int p){
//	if(ind ==0)
//		return;
//	if(visited[ind])
//		return;
//	if(tr[2][tr[0][ind]] == tr[2][ind] || tr[2][tr[1][ind]] == tr[2][ind])
//			return;
//	visited[ind] = true;
//	if(c == 'l'){
//		if(tr[2][tr[0][ind]] < tr[2][ind])
//			binaryT(tr[0][ind],'l',tr[2][ind]);
//		if(tr[2][tr[1][ind]] > tr[2][ind] && tr[2][tr[1][ind]] < p)
//			binaryT(tr[1][ind],'r',tr[2][ind]);		
//	}
//	if(c=='r'){
//		if(tr[2][tr[0][ind]] < tr[2][ind] && tr[2][tr[0][ind]] > p)
//			binaryT(tr[0][ind],'l',tr[2][ind]);
//		if(tr[2][tr[1][ind]] > tr[2][ind])
//			binaryT(tr[1][ind],'r',tr[2][ind]);			
//	}
//	return;
//}
//
//
//int main(){
//#ifdef _CONSOLE    
//	freopen("input.txt","r", stdin);
//	//	freopen("output.txt","w+", stdout);
//#endif
//	int tc;
//	cin>>tc;
//	while(tc--){
//		int n;
//		cin>>n;		
//		int L,R,K;
//		visited = vector<bool>(n+1,false);
//
//		tr[0].push_back(-1);
//		tr[1].push_back(-1);
//		tr[2].push_back(-1);
//		for(int i=0;i<n;i++){
//			cin>>L>>R>>K;
//			tr[0].push_back(L);
//			tr[1].push_back(R);
//			tr[2].push_back(K);
//		}
//		bool rstflg = false;
//		int cntZero = 0;
//		for(int i=1;i<n+1;i++){
//			if(tr[0][i] == 0)
//				cntZero++;
//			if(tr[1][i] == 0)
//				cntZero++;		
//		}
//		for(int i=1;i<n+1;i++){
//			bool flg = true;
//			if(n==1)
//				rstflg = true;
//			if(tr[0][i] == 0 && tr[1][i] == 0){
//				continue;
//			}			
//			visited[i] = true;
//			binaryT(tr[0][i],'l',tr[2][i]);
//			binaryT(tr[1][i],'r',tr[2][i]);
//			for(int i=1;i<n+1;i++){
//				if(!visited[i]){
//					flg = false;
//					break;
//				}
//			}
//			if(!flg)
//				for(int i=1;i<n+1;i++)
//					visited[i] = false;
//			else{
//				rstflg = flg;
//				break;
//			}
//		}
//		if(rstflg && cntZero == n+1)
//			cout<<"YES"<<endl;
//		else
//			cout<<"NO"<<endl;
//
//		tr[0].clear();
//		tr[1].clear();
//		tr[2].clear();
//		visited.clear();
//	}
//	return 0;
//}