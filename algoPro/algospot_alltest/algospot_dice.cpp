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
//long int cache[14][1001];
//vector<string> vt;
//int findv;
//
//long int finding(int num){
//	if(vt[num] == "d4")
//		return 4;
//	if(vt[num] == "d6")
//		return 6;
//	if(vt[num] == "d8")
//		return 8;
//	if(vt[num] == "d10")
//		return 10;
//	if(vt[num] == "d12")
//		return 12;
//	if(vt[num] == "d20")
//		return 20;
//
//	return 1;
//}
//long int rolldice(int num, int curv){	
//	if(num == n && findv == curv)
//		return 1;
//	if(num>=n)
//		return 0;
//
//	long int& ret = cache[num][curv];
//	if(ret != -1) return ret;
//	ret =0;
//
//	int lim = finding(num);
//
//	for(int i=1;i<=lim;i++){
//		if(curv+i<=findv)
//			ret += rolldice(num+1,curv+i);
//	}
//	return ret;
//}
//
//int main(){
//#ifdef _CONSOLE    
//	freopen("input.txt","r", stdin);
//	//	freopen("output.txt","w+", stdout);
//#endif
//	while(1){
//		
//		cin>>n;
//		if(n==0)
//			break;
//		
//		memset(cache,-1,sizeof(cache));
//		string str;
//		for(int i=0;i<n;i++){
//			cin>>str;
//			vt.push_back(str);
//		}		
//
//		cin>>findv;
//		long double sum=1.0;
//		for(int i=0;i<n;i++){
//			sum*=finding(i);
//		}
//
//		long int val = rolldice(0,0);
//
//		long double rst = val/sum;
//		cout.precision(5);
//		cout<<fixed<<rst<<endl;
//		vt.clear();
//	}
//	return 0;
//}