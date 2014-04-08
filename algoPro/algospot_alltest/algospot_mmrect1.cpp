//#include<iostream>
//#include<algorithm>
//#include<cmath>
//#include<vector>
//
//using namespace std;
//
//int main(){
//
//	int tc;
//	cin>>tc;
//	int point[50][2];
//	int n;
//	bool flag[2];
//	while(tc--){
//		cin>>n;
//		for(int i=0; i<n;i++)
//		{
//			cin>>point[i][0]>>point[i][1];
//		}
//		
//
//		vector<int> vt;
//		int mmin, mmax;
//
//		for(int i=0; i<n;i++)
//		{			
//			for(int j=i+1;j<n;j++){
//				flag[0] = false;
//				flag[1] = false;
//
//				if(abs(point[i][0]-point[j][0]) == abs(point[i][1] - point[j][1]))
//				{
//					for(int h=0;h<n;h++){
//						if(point[i][0] == point[h][0] && point[j][1]==point[h][1])
//							flag[0] = true;
//						if(point[i][1] == point[h][1] && point[j][0]==point[h][0])
//							flag[1] = true;
//					}
//					
//					if(flag[0] && flag[1])
//						vt.push_back(abs(point[i][0]-point[j][0]));
//				}
//			}
//		}
//
//		sort(vt.begin(),vt.end());
//
//		mmin = vt[0];
//		mmax = vt[vt.size()-1];
//
//		cout<<mmin<<" "<<mmax<<endl;
//
//
//	}
//
//	return 0;
//}