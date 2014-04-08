#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

char arr[7][4][4];
char brr[7][4][4];
void rotate(int);
void selfpR(int);
void selfmR(int);

int main(){

	int tc;
	cin>>tc;
	

	while(tc--){
		for(int i = 1;i<4;i++)
			for(int j=1;j<4;j++)
				cin>>arr[5][i][j];		
		for(int i = 1;i<4;i++)
			for(int k=1;k<5;k++)	
				for(int j=1;j<4;j++)
					cin>>arr[k][i][j];

		for(int i = 1;i<4;i++)
			for(int j=1;j<4;j++)
				cin>>arr[6][i][j];

		for(int k=1;k<7;k++)
			for(int i = 1;i<4;i++)
				for(int j=1;j<4;j++)
					brr[k][i][j] = arr[k][i][j];

		vector<int> vt;
		int a;
		while(1){
			cin>>a;
			if(a==0)
				break;
			vt.push_back(a);
		}
		int vSize;
		vSize = vt.size();

		
		/*for(int k=1;k<7;k++){
			for(int i = 1;i<4;i++){
				for(int j=1;j<4;j++)
					cout<<arr[k][i][j];
				cout<<endl;
			}
			cout<<endl;
		}*/
		
		for(int h=0;h<vSize;h++){
			rotate(vt[h]);

			for(int k=1;k<7;k++)
				for(int i = 1;i<4;i++)
					for(int j=1;j<4;j++)
						brr[k][i][j] = arr[k][i][j];

			/*for(int k=1;k<7;k++){
				for(int i = 1;i<4;i++){
					for(int j=1;j<4;j++)
						cout<<arr[k][i][j];
					cout<<endl;
			}
			cout<<endl;
			}*/
		}

		char temp;
		bool flg = true;

		for(int k=1;k<7;k++)
		{
			temp= arr[k][1][1];
			for(int i = 1;i<4;i++)
				for(int j=1;j<4;j++)
					if(temp != arr[k][i][j]) flg = false;
		}

		if(flg)
			cout<<"Yes, grandpa!"<<endl;
		else
			cout<<"No, you are wrong!"<<endl;		
	}

	return 0;
}

void rotate(int a){
	switch (a){
		case 1: {
			selfpR(a);
			arr[2][1][1] = brr[5][1][1];
			arr[2][2][1] = brr[5][2][1];
			arr[2][3][1] = brr[5][3][1];
			
			arr[6][1][1] = brr[2][1][1];
			arr[6][2][1] = brr[2][2][1];
			arr[6][3][1] = brr[2][3][1];

			arr[4][3][3] = brr[6][1][1];
			arr[4][2][3] = brr[6][2][1];
			arr[4][1][3] = brr[6][3][1];
			
			arr[5][1][1] = brr[4][3][3];
			arr[5][2][1] = brr[4][2][3];
			arr[5][3][1] = brr[4][1][3];
			break;}
		case -1: {
			selfmR(-a);			
			arr[5][1][1] = brr[2][1][1];
			arr[5][2][1] = brr[2][2][1];
			arr[5][3][1] = brr[2][3][1];
			
			arr[2][1][1] = brr[6][1][1];
			arr[2][2][1] = brr[6][2][1];
			arr[2][3][1] = brr[6][3][1];

			arr[6][1][1] = brr[4][3][3];
			arr[6][2][1] = brr[4][2][3];
			arr[6][3][1] = brr[4][1][3];
			
			arr[4][3][3] = brr[5][1][1];
			arr[4][2][3] = brr[5][2][1];
			arr[4][1][3] = brr[5][3][1];
			break;}
		case 2: {
			selfpR(a);
			arr[5][3][1] = brr[1][3][3];
			arr[5][3][2] = brr[1][2][3];
			arr[5][3][3] = brr[1][1][3];
			
			arr[3][1][1] = brr[5][3][1];
			arr[3][2][1] = brr[5][3][2];
			arr[3][3][1] = brr[5][3][3];

			arr[6][1][3] = brr[3][1][1];
			arr[6][1][2] = brr[3][2][1];
			arr[6][1][1] = brr[3][3][1];
			
			arr[1][3][3] = brr[6][1][3];
			arr[1][2][3] = brr[6][1][2];
			arr[1][1][3] = brr[6][1][1];
			break;}
		case -2: {
			selfmR(-a);
			arr[1][3][3] = brr[5][3][1];
			arr[1][2][3] = brr[5][3][2];
			arr[1][1][3] = brr[5][3][3];
			
			arr[6][1][3] = brr[1][3][3];
			arr[6][1][2] = brr[1][2][3];
			arr[6][1][1] = brr[1][1][3];

			arr[3][1][1] = brr[6][1][3];
			arr[3][2][1] = brr[6][1][2];
			arr[3][3][1] = brr[6][1][1];
			
			arr[5][3][1] = brr[3][1][1];
			arr[5][3][2] = brr[3][2][1];
			arr[5][3][3] = brr[3][3][1];
			break;}
		case 3: {
			selfpR(a);
			arr[2][1][3] = brr[6][1][3];
			arr[2][2][3] = brr[6][2][3];
			arr[2][3][3] = brr[6][3][3];
			
			arr[5][1][3] = brr[2][1][3];
			arr[5][2][3] = brr[2][2][3];
			arr[5][3][3] = brr[2][3][3];

			arr[4][3][1] = brr[5][1][3];
			arr[4][2][1] = brr[5][2][3];
			arr[4][1][1] = brr[5][3][3];
			
			arr[6][1][3] = brr[4][3][1];
			arr[6][2][3] = brr[4][2][1];
			arr[6][3][3] = brr[4][1][1];
			break;}
		case -3: {
			selfmR(-a);
			arr[2][1][3] = brr[5][1][3];
			arr[2][2][3] = brr[5][2][3];
			arr[2][3][3] = brr[5][3][3];
			
			arr[6][1][3] = brr[2][1][3];
			arr[6][2][3] = brr[2][2][3];
			arr[6][3][3] = brr[2][3][3];

			arr[4][3][1] = brr[6][1][3];
			arr[4][2][1] = brr[6][2][3];
			arr[4][1][1] = brr[6][3][3];
			
			arr[5][1][3] = brr[4][3][1];
			arr[5][2][3] = brr[4][2][1];
			arr[5][3][3] = brr[4][1][1];
			break;}
		case 4: {
			selfpR(a);
			arr[1][3][1] = brr[5][1][1];
			arr[1][2][1] = brr[5][1][2];
			arr[1][1][1] = brr[5][1][3];
			
			arr[6][3][3] = brr[1][3][1];
			arr[6][3][2] = brr[1][2][1];
			arr[6][3][1] = brr[1][1][1];

			arr[3][1][3] = brr[6][3][3];
			arr[3][2][3] = brr[6][3][2];
			arr[3][3][3] = brr[6][3][1];
			
			arr[5][1][1] = brr[3][1][3];
			arr[5][1][2] = brr[3][2][3];
			arr[5][1][3] = brr[3][3][3];
			break;}
		case -4: {
			selfmR(-a);
			arr[5][1][1] = brr[1][3][1];
			arr[5][1][2] = brr[1][2][1];
			arr[5][1][3] = brr[1][1][1];
			
			arr[3][1][3] = brr[5][1][1];
			arr[3][2][3] = brr[5][1][2];
			arr[3][3][3] = brr[5][1][3];

			arr[6][3][3] = brr[3][1][3];
			arr[6][3][2] = brr[3][2][3];
			arr[6][3][1] = brr[3][3][3];
			
			arr[1][3][1] = brr[6][3][3];
			arr[1][2][1] = brr[6][3][2];
			arr[1][1][1] = brr[6][3][1];
			break;}
		case 5: {
			selfpR(a);
			arr[1][1][1] = brr[2][1][1];
			arr[1][1][2] = brr[2][1][2];
			arr[1][1][3] = brr[2][1][3];
			
			arr[2][1][1] = brr[3][1][1];
			arr[2][1][2] = brr[3][1][2];
			arr[2][1][3] = brr[3][1][3];

			arr[3][1][1] = brr[4][1][1];
			arr[3][1][2] = brr[4][1][2];
			arr[3][1][3] = brr[4][1][3];
			
			arr[4][1][1] = brr[1][1][1];
			arr[4][1][2] = brr[1][1][2];
			arr[4][1][3] = brr[1][1][3];
			break;}
		case -5: {
			selfmR(-a);
			arr[3][1][1] = brr[2][1][1];
			arr[3][1][2] = brr[2][1][2];
			arr[3][1][3] = brr[2][1][3];
			
			arr[4][1][1] = brr[3][1][1];
			arr[4][1][2] = brr[3][1][2];
			arr[4][1][3] = brr[3][1][3];

			arr[1][1][1] = brr[4][1][1];
			arr[1][1][2] = brr[4][1][2];
			arr[1][1][3] = brr[4][1][3];
			
			arr[2][1][1] = brr[1][1][1];
			arr[2][1][2] = brr[1][1][2];
			arr[2][1][3] = brr[1][1][3];
			break;}
		case 6: {
			selfpR(a);
			arr[3][3][1] = brr[2][3][1];
			arr[3][3][2] = brr[2][3][2];
			arr[3][3][3] = brr[2][3][3];
			
			arr[4][3][1] = brr[3][3][1];
			arr[4][3][2] = brr[3][3][2];
			arr[4][3][3] = brr[3][3][3];

			arr[1][3][1] = brr[4][3][1];
			arr[1][3][2] = brr[4][3][2];
			arr[1][3][3] = brr[4][3][3];
			
			arr[2][3][1] = brr[1][3][1];
			arr[2][3][2] = brr[1][3][2];
			arr[2][3][3] = brr[1][3][3];
			break;}
		case -6: {
			selfmR(-a);
			arr[1][3][1] = brr[2][3][1];
			arr[1][3][2] = brr[2][3][2];
			arr[1][3][3] = brr[2][3][3];
			
			arr[2][3][1] = brr[3][3][1];
			arr[2][3][2] = brr[3][3][2];
			arr[2][3][3] = brr[3][3][3];

			arr[3][3][1] = brr[4][3][1];
			arr[3][3][2] = brr[4][3][2];
			arr[3][3][3] = brr[4][3][3];
			
			arr[4][3][1] = brr[1][3][1];
			arr[4][3][2] = brr[1][3][2];
			arr[4][3][3] = brr[1][3][3];
			break;}
		default: break;
	}
}

void selfpR(int a){
	arr[a][1][3] = brr[a][1][1];
	arr[a][2][3] = brr[a][1][2];

	arr[a][3][3] = brr[a][1][3];
	arr[a][3][2] = brr[a][2][3];
	
	arr[a][3][1] = brr[a][3][3];
	arr[a][2][1] = brr[a][3][2];

	arr[a][1][1] = brr[a][3][1];
	arr[a][1][2] = brr[a][2][1];
}
void selfmR(int a){
	arr[a][1][1] = brr[a][1][3];
	arr[a][1][2] = brr[a][2][3];

	arr[a][1][3] = brr[a][3][3];
	arr[a][2][3] = brr[a][3][2];
	
	arr[a][3][3] = brr[a][3][1];
	arr[a][3][2] = brr[a][2][1];

	arr[a][3][1] = brr[a][1][1];
	arr[a][2][1] = brr[a][1][2];
}