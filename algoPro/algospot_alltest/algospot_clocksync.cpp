//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int ckSwitch[10][5] = {{0,1,2,-1,-1},{3,7,9,11,-1},{4,10,14,15,-1},{0,4,5,6,7},{6,7,8,10,12},{0,2,14,15,-1},{3,14,15,-1,-1},{4,5,7,14,15},{1,2,3,4,5},{3,4,5,9,13}};
//int clck[16] = {0, };
//int cnt;
//int rst;
//bool flg = 0;
//
//void move(int a){
//	int clk = 0;
//	for(int i=0;i<5;i++)
//	{	
//		if(ckSwitch[a][i] == -1)
//			break;
//		clk = ckSwitch[a][i];
//		clck[clk]+=3;
//		if(clck[clk]>12)
//			clck[clk]-=12;
//	}
//	++cnt;
//}
//
//void find(int s){	
//	for(int i=0;i<4;i++){
//		if(i>0)
//			move(s);
//		for(int j=0;j<16;j++){
//			if(clck[j] != 12){
//				flg = 0;
//				break;
//			}
//			flg = 1;
//		}
//		if(flg==1 && rst>cnt)
//		{
//			flg=0;
//			rst = cnt;
//		}			
//		if(s<9)
//			find(s+1);		
//	}
//	move(s);
//	cnt-=4;		
//}
//
//int main(){
//	#ifdef _CONSOLE    
//	freopen("input.txt","r", stdin);
//	//	freopen("output.txt","w+", stdout);
//	#endif
//	
//	int tc;
//	cin>>tc;
//	while(tc--){
//		rst = 100000;
//		cnt = 0;
//		for(int i=0;i<16;i++)
//			clck[i] = 0;
//
//		for(int i=0;i<16;i++)
//			cin>>clck[i];
//	
//		find(0);
//	
//		if(rst == 100000)
//			cout<<-1<<endl;
//		else
//			cout<<rst<<endl;
//		
//	}
//	return 0;
//}