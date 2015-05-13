 #include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<vector<int> > vc;
vector<vector<bool> > visit;
int tx[] = { 1, 0, -1, 0 };
int ty[] = { 0, -1, 0, 1 };

bool edge(int cy, int cx){
	for (int i = 0; i < 4; i++)
	{
		if (cx + tx[i] < 0 || cy + ty[i] < 0
			|| cx + tx[i] >= m || cy + ty[i] >= n)
			return true;
	}
	return false;
}
void counting(int cy, int cx){
	visit[cy][cx] = true;
	for (int i = 0; i < 4; i++)
	{
		if (edge(cy + ty[i],cx + tx[i]))
			continue;
		if (!visit[cy + ty[i]][cx + tx[i]])
			counting(cy + ty[i], cx + tx[i]);

	}
}
int main(){
	cin >> n >> m;
	vc = vector < vector<int> >(n, vector<int>(m,0 ));
	visit = vector < vector<bool> >(n, vector<bool>(m, true));
	vector<pair<int, int> > pos;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> vc[i][j];
			pos.push_back(make_pair(i, j));			
		}
	}

	int year = 1;
	for (; year <= 10; year++){
		for (int i = 0; i < pos.size(); i++){
			visit[pos[i].first][pos[i].second] = false;
		}
		for (int i = 0; i < pos.size(); i++){
			
		}
	}

	

}
