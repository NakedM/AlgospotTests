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
//		int n,a,b;
//		cin>>n>>a>>b;
//
//		vector<long long> vt;
//		vt.push_back(1983);
//		priority_queue<long int, vector<long int>,greater<long int>> minpq;
//		priority_queue<long int, vector<long int>,less<long int>> maxpq;
//		maxpq.push(vt[0]);
//		long int rstsum = vt[0];
//
//		for(int i=1;i<n;i++){
//			long long t;
//			t = ((vt[i-1]*(long long)a)+b)%20090711;
//			//t = (t+b)%20090711;
//			vt.push_back(t);
//			
//			if(maxpq.size() == minpq.size())
//				maxpq.push(vt[i]);
//			else
//				minpq.push(vt[i]);
//				
//			if(maxpq.top() > minpq.top()){
//				long int tmp = maxpq.top();
//				maxpq.pop();
//				maxpq.push(minpq.top());
//				minpq.pop();
//				minpq.push(tmp);
//			}
//			
//			rstsum = (rstsum+maxpq.top())%20090711;
//		}
//		cout<<rstsum<<endl;
//	}
//	return 0;
//}