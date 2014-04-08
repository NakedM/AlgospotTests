//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//const int INTMAX = numeric_limits<int>::max();
//
//struct RMQ{
//
//	int n;
//
//	vector<int> rangeMin;
//
//	RMQ(const vector<int>& array){
//		n= array.size();
//		rangeMin.resize(n*4);
//		init(array,0,n-1,1);
//	}
//
//	int init(const vector<int>& array, int left, int right,int node){
//		if(left == right)
//			return rangeMin[node] = array[left];
//		int mid = (left + right)/2;
//		int leftMin = init(array, left, mid, node*2);
//		int rightMin = init(array, mid+1, right, node*2 +1);
//		return rangeMin[node] = min(leftMin,rightMin);
//	}
//
//	int query(int left, int right, int node, int nodeLeft, int nodeRight){
//		if(right<nodeLeft || nodeRight<left) return INTMAX;
//		if(left<=nodeLeft && nodeRight <=right) return rangeMin[node];
//
//		int nodeMid = (nodeLeft + nodeRight)/2;
//		return min(query(left,right,node*2,nodeLeft,nodeMid),query(left,right,node*2+1,nodeMid+1,nodeRight));
//	}
//
//	int query1(int left, int right){
//		return query(left,right,1,0,n-1);
//	}
//};
//
//int main(){
//
//	int tc;
//	cin>>tc;
//
//	while(tc--){
//		int n,q;
//		cin>>n>>q;
//
//		int mmin, mmax;
//
//		vector<int> vt;
//		vector<int> vt2;
//		int h;
//		for(int i=0;i<n;i++){
//			cin>>h;
//			vt.push_back(h);
//			vt2.push_back(-h);
//		}
//		int a,b;
//
//		RMQ r(vt);
//		RMQ r2(vt2);
//
//		for(int i=0;i<q;i++){
//
//			cin>>a>>b;
//			mmin = (r.query1(a,b));
//			mmax = (r2.query1(a,b));
//
//			cout<<abs(mmax)-mmin<<endl;
//		}
//
//	}
//
//	return 0;
//}