//#include<iostream>
//#include<algorithm>
//#include<vector>
//
////#define INF 999999999
//using namespace std;
//
//vector<int> fire;
//vector<int> vt;
//vector<int> v;
//
//int p,n;
//
//bool minh(int first, int second){
//	return first<second;
//}
//
//void cal(int k){
//	if(k==n+2) return;
//
//	int& rst = fire[k];
//	if(rst !=-1) return;
//	
//	rst = vt[k];
//	
//	if(k>p){
//		for(int j=1;j<=p;j++) v.push_back(fire[k-j]);
//		
//		sort(v.begin(),v.end(),minh);
//		
//		rst += v.front();
//		v.clear();
//	}
//
//	/*
//	if(k>p){
//		for(int j=1;j<=p;j++) v.push_back(fire[k-j]);
//		//iter = v.begin();
//		make_heap(v.begin(),v.end(),minh);
//		//int temp = v.back();
//		rst += v.front();
//	} else if(k>p){
//		
//		v.push_back(fire[k-1]);
//		push_heap(v.begin(),v.end(),minh);
//
//		bool flag = false;
//		for(int i=0;i<p;i++){
//			if(v.front()==fire[k-i-1]){
//				flag = true;
//			}
//		}
//
//		if(!flag){		
//			pop_heap(v.begin(),v.end(),minh);
//			v.pop_back();	
//		}
//
//		rst += v.front();		
//	}*/
//	cal(k+1);
//	
//	return;
//}
//
//
//int main(){
//
//	int tc;
//	cin>>tc;
//	while(tc--){
//		
//		cin>>n>>p;
//
//		/*for(int i=0;i<100003;i++){
//			fire[i] = -1;
//		}*/
//
//		
//		int t;
//		vt.push_back(0);
//		for(int i=0;i<n;i++){
//			cin>>t;
//			vt.push_back(t);
//		}
//		vt.push_back(0);
//
//		for(int i=0;i<vt.size();i++){
//			fire.push_back(-1);
//		}
//
//		cal(0);
//
//		cout<<fire[n+1]<<endl;
//
//		vt.clear();
//	}
//
//
//	return 0;
//}