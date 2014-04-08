//#include<iostream>
//#include<fstream>
//#include<string>
//#include<cstring>
//#include<cmath>
//#include<vector>
//#include<algorithm>
//#include<queue>
//#include<limits>
//using namespace std;
//
//ifstream in("input.txt");
//int linec = 1;
//int main(){
//#ifdef _CONSOLE    
//	freopen("input.txt","r", stdin);
//	//	freopen("output.txt","w+", stdout);
//#endif
//	int tc;
//	cin>>tc;
//	while(tc--){		
//		int r;
//		int c;		
//		cin>>r;
//		cin>>c;
//		string str;
//		cin>>str;
//		char pan[22][22];
//		//for(int i=0;i<22;i++)
//		//	memset(pan[i],'\0',sizeof(pan[i]));
//		
//		int chrcnt = str.length()/5;
//		int a =1, b=1;
//		for(int i=0;i<str.length();i++){
//			pan[a][b] = str[i];
//			b++;
//			if(b>c){
//				b=1;
//				a++;
//			}
//		}
//
//		vector<string> rst(chrcnt);
//		int direction =0;
//		a=1;
//		b=1;
//		int cnt = 0;
//		int nb = 2, eb = c, sb =r, wb = 1;
//		for(int i=0;i<str.length();i++){
//			cnt = i/5;
//			if(cnt >= chrcnt) break; 
//			rst[cnt] += pan[a][b];
//			if(direction == 0){
//				b++;
//				if(b>eb) {direction++; eb--; b--; a++;}
//			}
//			else if(direction == 1){
//				a++;
//				if(a>sb) {direction++; sb--; a--; b--;}
//			}
//			else if(direction ==2){
//				b--;
//				if(b<wb) {direction++; wb++; b++; a--;}
//			}
//			else if(direction ==3){
//				a--;
//				if(a<nb) {direction++; nb++;a++;b++;}
//			}
//			direction %= 4;
//		}
//		vector<int> rstint(chrcnt);
//		vector<char> rstchr(chrcnt);
//		for(int i=0;i<chrcnt;i++){
//			rstint[i] = stoi(rst[i],nullptr,2);
//			rstchr[i] = rstint[i] + 'A' -1;
//		}
//		cout<<linec<<" ";
//		for(int i = 0;i<chrcnt;i++){
//			if(rstchr[i] == 'A' -1)
//				cout<<" ";
//			else
//				cout<<rstchr[i];
//		}
//		cout<<endl;
//		linec++;
//		
//
//	}
//	return 0;
//}