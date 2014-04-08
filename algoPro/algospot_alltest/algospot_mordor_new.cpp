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

#pragma warning(disable:4996)
ifstream in("input.txt");


struct Node{
	int start;
	int fin;
	int minn;
	int maxx;

	Node *parentnode;
	Node *leftnode;
	Node *rightnode;

	Node(){
		start = -1;
		fin = -1;
		minn = -1;
		maxx = -1;
		parentnode = NULL;
		leftnode = NULL;
		rightnode = NULL;
	}
};

Node preproc(Node* p)
{
	if(p->fin - p->start == 0)
		return NULL;
	Node *leftn = new Node();
	Node *rightn = new Node();
}

int main(){
#ifdef _HONG    
	freopen("input.txt","r", stdin);
	//	freopen("output.txt","w+", stdout);
#endif
	int tc;
	cin>>tc;
	while(tc--){
		int n,q;
		cin>>n>>q;

		vector<int> way(0,n);
		int tmp;
		for(int i=0;i<n;i++)
		{
			cin>>tmp;
			way[i] = tmp;
		}

		Node roott;
		
		


	}
	return 0;
}