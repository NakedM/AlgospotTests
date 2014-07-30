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
#include<map>
using namespace std;

#pragma warning (disable:4996)
ifstream in("input.txt");

int V;

int adj[MAX_V][MAX_V];
int C[MAX_V][MAX_V][MAX_V];
void allPairShortestPath1(){

	for (int i = 0; i < V; i++){
		for (int j = 0; j < V; j++){
			if (i != j)
				C[0][i][j] = min(adj[i][j], adj[i][0] + adj[0][j]);
			else
				C[0][i][j] = 0;
		}
	}

	for(int k=1;k<V;k++)
		for(int i=0;i<V;i++)
			for (int j = 0; j < V; j++)
				C[k][i][j] = min(C[k - 1][i][j], C[k - 1][i][k] + C[k - 1][k][j]);


}





int main(){
#ifdef _HONG
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		string str;
		cin >> str;

		vector<int> vc = getSuffixArray(str);

		for (int i = 0; i < vc.size(); i++)
			cout << vc[i] << " ";
		cout << endl;


	}
	return 0;
}