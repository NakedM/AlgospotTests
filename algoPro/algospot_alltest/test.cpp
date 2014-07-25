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

const int INT_MAXX = numeric_limits<int>::max(); //INT_MAX 는 예약어 이미 정의되어 있음.
struct RMQ {
	int n;

	vector<int> rangeMin;
	RMQ(const vector<int>& array){
		n = array.size();
		rangeMin.resize(n * 4);
		init(array, 0, n - 1, 1);
	}

	int init(const vector<int>& array, int left, int right, int node){
		if (left == right)
			return rangeMin[node] = array[left];
		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node * 2);
		int rightMin = init(array, mid + 1, right, node * 2 + 1);
		return rangeMin[node] = min(leftMin, rightMin);
	}

	int query(int left, int right, int node, int nodeLeft, int nodeRight){
		if (right < nodeLeft || nodeRight < left)
			return INT_MAXX;
		if (left <= nodeLeft && nodeRight <= right)
			return rangeMin[node];

		int mid = (nodeLeft + nodeRight) / 2;
		return min(query(left, right, node * 2, nodeLeft, mid),
			query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}
	//외부에서 호출하기 위해
	int query(int left, int right){
		return query(left, right, 1, 0, n - 1);
	}

	int update(int index, int newValue, int node, int nodeLeft, int nodeRight){
		if (index < nodeLeft || nodeRight < index)
			return rangeMin[node];

		if (nodeLeft == nodeRight) return rangeMin[node] = newValue;
		int mid = (nodeLeft + nodeRight) / 2;
		return rangeMin[node] = min(
			update(index, newValue, node * 2, nodeLeft, mid),
			update(index, newValue, node * 2 + 1, mid + 1, nodeRight));
	}

	//외부에서 호출하기 위해
	int update(int index, int newValue){
		return update(index, newValue, 1, 0, n - 1);
	}

};



};




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