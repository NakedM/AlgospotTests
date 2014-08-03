#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<limits>
#include<bitset>
#include<map>
using namespace std;

#pragma warning (disable:4996)
ifstream in("input.txt");



const int INF = 987654321;

struct bst{
	int leftindex = 0;
	int rightindex = 0;
	int key = -1;
};


vector<bool> visit;
vector<bst> nodes;


int binary(int rootind){
	if (rootind == 0)
		return 1;

	if (visit[rootind])
		return INF;

	int ret = 1;
	visit[rootind] = true;

	int rootkey = nodes[rootind].key;
	int leftkey = nodes[nodes[rootind].leftindex].key;
	int rightkey = nodes[nodes[rootind].rightindex]	.key;

	if (leftkey < rootkey)
		ret+=binary(nodes[rootind].leftindex);
	if (rightkey == -1 || rightkey > rootkey)
		ret += binary(nodes[rootind].rightindex);

	return ret;
}

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		nodes.clear();
		vector<bool> keys(1001, false);
		bool overlap = false;
		int n;
		cin >> n;
		
		bst node;
		nodes.push_back(node);

		int a, b, c;
		for (int i = 0; i < n; i++){
			cin >> a >> b >> c;
			node.leftindex = a;
			node.rightindex = b;
			node.key = c;
			if (!keys[c])
				keys[c] = true;
			else
				overlap = true;

			
			nodes.push_back(node);
		}

		

		int allnode = n * 2 + 1;
		bool flg = false;
		//int ch;

		for (int i = 1; i <= n; i++){
			visit = vector<bool>(n + 1, false);
			if (allnode == binary(i)){
				//ch = i;
				flg = true;
				break;
			}
		}


		if (!overlap && flg){
			//cout << ch << endl;
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;
	}
	return 0;
}