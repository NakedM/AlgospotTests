//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//
//bool pan[22][22];
//int h,w;
//
//int cover(){
//	int bx=0;
//	int by=0;
//	int rst = 0;
//	bool flg = false;
//	for(int i=1;i<h+1;i++){
//		for(int j=1;j<w+1;j++){
//			if(pan[i][j]){
//				bx = j;
//				by = i;
//				flg = true;
//				break;
//			}
//		}
//		if(flg) break;
//	}
//	if(bx==0 && by ==0)
//		return 1;
//	else if(pan[by][bx])
//	{
//		if(pan[by+1][bx] && pan[by][bx+1]){
//			pan[by][bx] = pan[by+1][bx] = pan[by][bx+1] = false;
//			rst+=cover();
//			pan[by][bx] = pan[by+1][bx] = pan[by][bx+1] = true;
//		}
//		if(pan[by+1][bx] && pan[by+1][bx-1]){
//			pan[by][bx] = pan[by+1][bx] = pan[by+1][bx-1] = false;
//			rst+=cover();
//			pan[by][bx] = pan[by+1][bx] = pan[by+1][bx-1] = true;
//		}
//		if(pan[by][bx+1] && pan[by+1][bx+1]){
//			pan[by][bx] = pan[by][bx+1] = pan[by+1][bx+1] = false;
//			rst+=cover();
//			pan[by][bx] = pan[by][bx+1] = pan[by+1][bx+1] = true;
//		}
//		if(pan[by+1][bx] && pan[by+1][bx+1]){
//			pan[by][bx] = pan[by+1][bx] = pan[by+1][bx+1] = false;
//			rst+=cover();
//			pan[by][bx] = pan[by+1][bx] = pan[by+1][bx+1] = true;
//		}
//	}
//	return rst;
//}
//
//int main(){
//	#ifdef _CONSOLE    
//	freopen("input.txt","r", stdin);
//	//	freopen("output.txt","w+", stdout);
//	#endif
//	int tc;
//	cin>> tc;	
//
//	while(tc--){
//		memset(pan,false,sizeof(pan));
//		cin>>h>>w;
//		
//		char t;
//		int cnt = 0;
//		for(int i=1;i<h+1;i++){
//			for(int j=1;j<w+1;j++){
//				cin>>t;
//				if(t == '.'){
//					cnt++;
//					pan[i][j] = true;
//				}				
//			}
//		}	
//		if(cnt%3 != 0)
//			cout<<0<<endl;
//		else{
//			cout<<cover()<<endl;
//		}
//	}
//	return 0;
//}