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

void postorder(vector<int>& preorder, vector<int>& inorder, int n)
{
	if (preorder.empty())
		return;
	
	int root = preorder[0];
	int rootpos = -1;

	int sz = inorder.size();
	for (int i = 0; i < sz; i++)
	{
		if (root == inorder[i])
			rootpos = i;
	}
	vector<int> pre1(preorder.begin() + 1, preorder.begin() + rootpos+1);
	vector<int> pre2(preorder.begin() + rootpos+1, preorder.end());
	vector<int> in1(inorder.begin(), inorder.begin() + rootpos);
	vector<int> in2(inorder.begin() + rootpos  +1, inorder.end());

	postorder(pre1, in1, n);
	postorder(pre2, in2, n);

	
	cout << root;
	if (n != preorder.size())
		cout << " ";
	else
		cout << endl;
}

int main(){
#ifdef _HONG    
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--){
		int n;
		cin >> n;
		vector<int> preorder(n);
		vector<int> inorder(n);

		for (int i = 0; i < n; i++)
			cin >> preorder[i];

		for (int i = 0; i < n; i++)
			cin >> inorder[i];

		
		postorder(preorder, inorder, n);

	}
	return 0;
}