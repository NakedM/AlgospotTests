#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits>
#include<bitset>
using namespace std;

#pragma warning (disable:4996)
ifstream in("input.txt");

int score(double dis){
	if (dis <= 3.0)
		return 100;
	else if (dis <= 6.0)
		return 80;
	else if (dis <= 9.0)
		return 60;
	else if (dis <= 12.0)
		return 40;
	else if (dis <= 15.0)
		return 20;
	else
		return 0;

	return 0;
}

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;

	//3 6 9 12 15
	while (tc--){
		vector<pair<double,double> > firstman;
		vector<pair<double, double> > secondman;

		double tx, ty;

		for (int i = 0; i < 3; i++){
			cin >> tx >> ty;
			firstman.push_back(make_pair(tx, ty));

		}
		for (int i = 0; i < 3; i++){
			cin >> tx >> ty;
			secondman.push_back(make_pair(tx, ty));

		}
		int firstscore = 0;
		int secondscore = 0;

		for (int i = 0; i < 3; i++){
			double x = firstman[i].first;
			double y = firstman[i].second;

			double dis = x*x + y*y;
			dis = sqrt(dis);

			firstscore += score(dis);
		}

		for (int i = 0; i < 3; i++){
			double x = secondman[i].first;
			double y = secondman[i].second;

			double dis = x*x + y*y;
			dis = sqrt(dis);

			secondscore += score(dis);
		}

		if (firstscore == secondscore)
			cout << "SCORE: " << firstscore << " to " << secondscore << ", TIE." << endl;
		else if(firstscore > secondscore)
			cout << "SCORE: " << firstscore << " to " << secondscore << ", PLAYER 1 WINS."<< endl;
		else
			cout << "SCORE: " << firstscore << " to " << secondscore << ", PLAYER 2 WINS." << endl;


	}
	return 0;
}