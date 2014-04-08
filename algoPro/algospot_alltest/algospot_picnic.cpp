//#include<iostream>
//#include<algorithm>
//using namespace std;
//bool person[10][10];
//bool matched[10];
//int rst = 0;
//int psn_num;
//int match_num;
//void find(){	
//	int psn_index = -1;	
//	for(int i =0; i<psn_num; i++){
//		if(matched[i] == 0)	{
//			psn_index = i;	
//			break;
//		}	
//	}	
//	if(psn_index == -1)	{
//		rst++;	
//		return;
//	}	
//	else 	{	
//		for(int i = 0; i<psn_num; i++)		{	
//			if(person[psn_index][i] == 1 && matched[i] == 0)
//			{				
//				matched[psn_index] = 1;				
//				matched[i] = 1;			
//				find();			
//				matched[psn_index] = 0;	
//				matched[i] = 0;	
//			}	
//		}
//	}
//}
//int main(){
//	int prob;
//	int a,b;
//	cin >> prob;
//	while(prob--){
//		rst = 0;
//		cin>>psn_num>>match_num;
//		for(int i =0; i<10; i++)
//			for(int j=0; j<10;j++)	
//				person[i][j] = 0;
//		for(int i=0; i<10; i++)	
//			matched[i] = 0;	
//		for(int i=0; i<match_num; i++){
//			cin>>a>>b;	
//			person[a][b] = 1;
//			person[a][b] = 1;
//		}
//		find();
//		cout<<rst<<endl;
//	}
//	return 0;
//}//988b 5ms
//
//
//
//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<cstring>
//
//using namespace std;
//
//int n;
//int m;
//vector<vector<int>> vt;
//int rst=0;
//bool bmatched[10];
//int matching(int rst){
//	rst=0;
//	int ind = -1;
//	for(int i =0; i<n; i++){
//		if(bmatched[i] == false)	{
//			ind = i;	
//			break;
//		}	
//	}	
//	if(ind == -1){		
//		return 1;
//	}	
//	else{
//		for(int i = 0; i<vt[ind].size(); i++){	
//			if(bmatched[vt[ind][i]] == false){				
//				bmatched[ind] = true;
//				bmatched[vt[ind][i]] = true;
//				//cout<<ind<<" "<<vt[ind][i]<<endl;
//				rst += matching(rst);
//				bmatched[ind] = false;
//				bmatched[vt[ind][i]] = false;
//				
//			}	
//		}		
//	}
//	return rst;
//}
//
//int main(){
//	#ifdef _CONSOLE    
//	freopen("input.txt","r", stdin);
//	//	freopen("output.txt","w+", stdout);
//#endif
//	int tc;
//	cin>>tc;
//	while(tc--){
//		cin>>n>>m;
//		vt = vector<vector<int>>(n);
//		memset(bmatched,false,sizeof(bmatched));
//		int a,b;
//		for(int i=0;i<m;i++){
//			cin>>a>>b;
//			vt[a].push_back(b);
//			vt[b].push_back(a);
//		}
//		cout<<matching(0)<<endl;
//		vt.clear();
//	}
//	return 0;
//}
