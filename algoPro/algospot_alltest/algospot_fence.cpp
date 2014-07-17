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
//int n;
//vector<int> vt;
//
//int fence(int left, int right){
//	if(left == right)
//		return vt[left];
//
//	int mid = (left+right)/2;
//	int rst = max(fence(left,mid),fence(mid+1,right));
//
//	int l = mid, r= mid+1;
//	int height = min(vt[l],vt[r]);
//
//	rst = max(rst,height*2);
//
//	while(left<l || right>r){
//		if(left<l && (right == r || vt[l-1] > vt[r+1])){
//			l--;
//			height = min(height,vt[l]);
//		}
//		else{
//			r++;
//			height = min(height,vt[r]);
//		}
//		rst = max(rst,height*(r-l+1));
//	}
//	return rst;
//}
//
//int main(){
//#ifdef _CONSOLE    
//	freopen("input.txt","r", stdin);
//		freopen("output.txt","w+", stdout);
//#endif
//	int tc;
//	cin>>tc;
//	while(tc--){
//		cin>>n;
//
//		int a;
//		for(int i=0;i<n;i++){
//			cin>>a;
//			vt.push_back(a);
//		}
//
//		cout<<fence(0,vt.size()-1)<<endl;
//		vt.clear();
//	}
//	return 0;
//}