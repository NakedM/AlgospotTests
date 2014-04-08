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
//int linec = 1;
//
//int main(){
//#ifdef _CONSOLE    
//	freopen("input.txt","r", stdin);
//	//	freopen("output.txt","w+", stdout);
//#endif
//	int tc;
//	cin>>tc;
//	while(tc--){
//		int r,c;
//		cin>>r>>c;
//		string str;
//		//cin>>str;
//		cin.ignore();
//		getline(cin,str);
//		int chrcnt = (r*c)/5;
//		int remain = (r*c)%5;
//
//		vector<bitset<5>> bt(chrcnt);
//		vector<string> strvt(chrcnt);
//		for(int i=0;i<str.length();i++){
//			char t;
//			t = str[i];
//			if(t==' ')
//				bt[i]=0;
//			else
//				bt[i] = t-'A'+1;
//		}
//
//		for(int i=0;i<chrcnt;i++){
//			strvt[i] = bt[i].to_string();
//		}
//
//		bool pan[23][23];
//		for(int i=0;i<23;i++)
//			memset(pan[i],false,sizeof(pan[i]));
//		int a=1,b=1;
//		pan[a][b] = strvt[0][0]-'0';
//		int direct = 0;
//		int nb = 2, eb = c, sb =r, wb = 1;
//		for(int i=1;i<r*c-remain;i++){
//			if(direct == 0){
//				b++;
//				if(b>eb) {direct++;b--;eb--;}
//			}
//			if(direct == 1){
//				a++;
//				if(a>sb) {direct++;a--;sb--;}
//			}
//			if(direct == 2){
//				b--;
//				if(b<wb) {direct++;b++;wb++;}
//			}
//			if(direct == 3){
//				a--;
//				if(a<nb) {direct++;a++;nb++;b++;}
//			}
//			direct %= 4;
//
//			pan[a][b] = strvt[i/5][i%5] - '0';
//		}
//
//		cout<<linec<<" ";
//
//		for(int i=1;i<r+1;i++){
//			for(int j=1;j<c+1;j++){
//				if(pan[i][j])
//					cout<<"1";
//				else
//					cout<<"0";
//			}			
//		}
//
//		cout<<endl;
//		linec++;
//	}
//	return 0;
//}