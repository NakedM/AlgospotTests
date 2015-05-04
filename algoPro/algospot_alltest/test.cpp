#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
	int c, r;
	cin >> c >> r;
	int k;
	cin >> k;
	int x = 0, y = 0;
	int tc = c, tr = r;
	int sn = 0;
	int count = 0;

	if (k > c*r)
	{
		cout << 0 << endl;
		return 0;
	}
	while (tc > 0 || tr > 0){
		int line = tr * 2 + (tc - 2) * 2;		
		count++;
		if (k <= line+sn)
		{
			if (k - sn <= tr - 1){
				x = count;
				y = k - sn + count - 1;
			}
			else if (k - sn <= tr - 1 + tc - 1){
				x = k - sn - tr + count;
				y = tr + count - 1;
			}
			else if (k - sn <= (tr - 1) * 2 + tc - 1){
				x = tc + count - 1;
				y = tr + count - (k - sn - (tr-1) - (tc-1));
			}
			else{
				x = tc + count - (k - sn - (tr-1) * 2 - (tc-1));
				y = count;
			}
			break;
		}
		tr -= 2;
		tc -= 2;
		sn += line;
	}
	cout << x << " " << y << endl;

	return 0;

}
