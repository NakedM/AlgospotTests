#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> fn(31);
	vector<int> gn(31);

	fn[0] = 1;
	fn[1] = 0;
	gn[0] = 0;
	gn[1] = 1;

	for (int i = 2; i < n + 1; i++)
	{
		fn[i] = fn[i - 2] + 2 * gn[i - 1];
		gn[i] = fn[i - 1] + gn[i - 2];
	}

	cout << fn[n] << endl;
	
	return 0;
}
