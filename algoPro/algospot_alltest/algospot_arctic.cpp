#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<iterator>
using namespace std;

#pragma warning (disable:4996)
ifstream in("input.txt");

struct line{
	double dis;
	int left;
	int right;
};

bool compareSt(line l1, line l2){
	return (l1.dis < l2.dis);
}

int main(){
#ifdef _CONSOLE    
	freopen("input.txt", "r", stdin);
#endif
	int tc;
	cin>>tc;
	while(tc--){
		int n;
		cin>>n;
		
		vector<pair<int,int> > parent;
		for (int i = 0; i < n; i++)
			parent.push_back(make_pair(i,1));

		vector<pair<double, double> > point(n,make_pair(0.0,0.0));

		double t1, t2;
		for (int i = 0; i < n; i++)
		{
			cin >> t1 >> t2;
			point[i] = make_pair(t1, t2);
		}

		vector<vector<double> > vc;
		vector<double> tmp(n, 10000000.0);
		for (int i = 0; i < n; i++)
			vc.push_back(tmp);

		vector<line> lines;

		for (int i = 0; i < n; i++){
			for (int j = i+1; j < n; j++)
			{
				double x = point[i].first - point[j].first;
				double y = point[i].second - point[j].second;
				double dis = x*x + y*y;

				vc[i][j] = dis;
				vc[j][i] = dis;
				
				line ls = { dis, i, j };
				lines.push_back(ls);
			}			
		}

		int linesz = lines.size();
		sort(lines.begin(), lines.end(), compareSt);
		int ind = 0;
		vector<double> distances;

		while (parent[0].second < n){
			int le = lines[ind].left;
			int ri = lines[ind].right;

			if (parent[le].first != parent[ri].first){
				if (parent[le].first > parent[ri].first){
					int tp = parent[le].first;
					for (int i = 0; i < n; i++){
						if (parent[i].first == tp){
							parent[i].first = parent[ri].first;
						}
					}
					int tsum = parent[ri].second + parent[le].second;
					parent[ri].second = tsum;
					parent[le].second = tsum;
					distances.push_back(lines[ind].dis);
				}
				else{
					int tp = parent[ri].first;
					for (int i = 0; i < n; i++){
						if (parent[i].first == tp){
							parent[i].first = parent[le].first;
						}
					}
					int tsum = parent[ri].second + parent[le].second;
					parent[ri].second = tsum;
					parent[le].second = tsum;
					distances.push_back(lines[ind].dis);
				}
			}
			ind++;
			if (ind >= linesz)
				break;
		}

		double result = distances[n-2];

		cout.precision(2);
		cout << fixed;
		cout << sqrt(result) << endl;

	}
	return 0;
}