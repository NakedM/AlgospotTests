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
//double rst[51] = {-1.0,};
//int city[51][51] = {{0,0},};
//double cache[51][101] = {{-1.0,-1.0},};
//int afterday;
//int n;
//int prison;
//int sum[51] = {0,};
//
//double move(int dday, int pos, int fi){	
//	if(dday==afterday){
//		if(fi == pos)
//			return 1.0;
//		else
//			return 0.0;
//	}
//	double& ret = cache[pos][dday];
//	if(ret>-0.5) return ret;
//	ret = 0.0;
//	double nextval = 1/double(sum[pos]);
//
//	for(int i=0;i<n;i++)
//		if(city[pos][i] == 1)
//			ret += move(dday+1,i,fi)*nextval;
//	return ret;
//}
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
//		
//		cin>>n;		
//		cin>>afterday;		
//		cin>>prison;
//
//		for(int i=0;i<51;i++){
//			rst[i] = -1.0;
//			sum[i] = 0;
//			for(int j=0;j<101;j++)
//				cache[i][j] = -1.0;
//		}				
//		for(int i=0;i<n;i++){
//			for(int j=0;j<n;j++){
//				cin>>city[i][j];
//			}
//		}
//		for(int i=0;i<n;i++){
//			for(int j=0;j<n;j++){
//				if(city[i][j])
//					sum[i]++;
//			}
//		}		
//		int cntcity;
//		cin>>cntcity;
//		//vector<int> cityvt;
//		int t;
//		for(int i=0;i<cntcity-1;i++){			
//			cin>>t;
//			printf("%.8f",move(0,prison,t));
//			cout<<" ";
//			//printf("%.8f",cache[2][0]);
//			//printf("%.8f",move(0,prison,t));
//			
//		}
//		cin>>t;
//		printf("%.8f",move(0,prison,t));
//		cout<<endl;
//		//move(0,prison,1.0);
//		
//		/*for(int i=0;i<cityvt.size();i++){
//			printf("%.8f",rst[cityvt[i]]);
//			if(i==cityvt.size()-1)
//				cout<<endl;
//			else
//				cout<<" ";
//		}*/
//	}
//	return 0;
//}
//
////#include <iostream>
////
////using namespace std;
////
////#define REP(variable, repeatnumber) for(int variable=0; variable<repeatnumber; variable++)
////#define FOR(variable, start, end) for(int variable=start; variable<=end; variable++)
////
////int main()
////{
////	bool edge[52][52]; // 마을 지도
////	int neig[51] = {0}; // 이웃
////	int c, n, day, prison, t, num, current, yesterday;
////	double sol[2][51] = {0}; // 확률 table
////
////	cin>>c;
////
////	while(c--)
////	{
////		cin>>n>>day>>prison;
////
////		REP(i, n)
////		{
////			REP(j, n)
////			{
////				scanf("%d", &edge[i][j]);
////				if(edge[i][j]) ++neig[i];
////			}
////		}
////		sol[0][prison] = 1.0; // 죄수가 0번째 날에 감옥에 있을 확률 = 100%
////
////		FOR(d, 1, day)
////		{
////			current = d%2;
////			yesterday = (d+1)%2;
////
////			REP(i, n) // i번 마을에서
////				REP(j, n) // j번 마을로 가는
////					if(edge[i][j]) // 길이 있으면
////						sol[current][j] += sol[yesterday][i]/neig[i];
////			REP(i, n) sol[yesterday][i] = 0; // 사용한 데이터 버림
////		}
////
////		cin>>t;
////		REP(i, t-1)
////		{
////			cin>>num;
////			printf("%.8f ", sol[current][num]);
////		}
////		cin>>num;
////		printf("%.8f\n", sol[current][num]);
////
////		REP(i, n) {neig[i]=0; sol[0][i]=0; sol[1][i]=0;} // 각 테스트케이스마다 초기화
////	}
////
////	return 0;
////}
