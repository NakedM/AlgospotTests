//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<string>
//
//using namespace std;
//
//int main(){
//
//	int tc;
//	cin>>tc;
//
//	vector<string> team;
//	vector<int> vtwin;
//	vector<int> game;
//	vector<pair<double,string>> perwin;
//	vector<string> remteam;
//
//	while(tc--){
//		string str;
//		int win=0,draw=0,lose=0;
//		string myteam;
//		int remgame=0;
//		team.clear();
//		vtwin.clear();
//		game.clear();
//		remteam.clear();
//		perwin.clear();
//
//		for(int i=0;i<8;i++){
//			cin>>str>>win>>draw>>lose;
//			team.push_back(str);
//			vtwin.push_back(win);
//			game.push_back(win+draw+lose);
//		}
//
//		cin>>myteam;
//		cin>>remgame;
//		string t;
//
//		for(int i=0;i<(remgame*2);i++){
//			cin>>t;
//			remteam.push_back(t);
//		}
//
//		for(int i=0;i<remteam.size();i++){
//			if(remteam[i] == myteam){
//				for(int j=0;j<8;j++){
//					if(team[j] == remteam[i]){
//						++vtwin[j];
//						++game[j];
//						break;
//					}
//				}
//			}
//			else {
//				for(int j=0;j<8;j++){
//					if(team[j] == remteam[i]){
//						++game[j];
//						break;
//					}
//				}
//
//			}
//		}
//
//
//		double pw =0;
//		for(int i=0;i<8;i++){
//			if(game[i] != 0)
//				pw = (double)vtwin[i]/(double)game[i];
//			else
//				pw = 0;
//			perwin.push_back(make_pair(pw,team[i]));
//		}
//
//		sort(perwin.begin(),perwin.end());
//		reverse(perwin.begin(),perwin.end());
//
//		for(int i =0; i<8;i++){
//			if(perwin[i].second == myteam && perwin[i].first == perwin[3].first)
//				swap(perwin[3],perwin[i]);
//		}
//
//		bool fflg = false;
//		for(int i =0; i<4;i++){
//			if(perwin[i].second == myteam)
//				fflg = true;
//		}
//
//		if(fflg)
//			cout<<"YES"<<endl;
//		else
//			cout<<"NO"<<endl;
//	}
//
//	return 0;
//}