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

class ttest {
public:
	int x;
	ttest(){
		x = 0;
	}

	void virtual draw() = 0;
};

class child : ttest{

	void virtual draw(){ };
};


int main(){

	vector<int> vc;

	for (int i = 0; i < 10; i++){
		vc.push_back(i);
		cout << "capapciti : " << vc.capacity() << endl;
		cout << "size : " << vc.size() << endl;
		cout << "first address : " << &vc[0] << endl;

	}

	vc.insert(vc.begin() + 4, 5);
	cout << "capapciti : " << vc.capacity() << endl;
	cout << "size : " << vc.size() << endl;
	cout << "first address : " << &vc[0] << endl;

	child* ch = new child();
	
	return 0;
}