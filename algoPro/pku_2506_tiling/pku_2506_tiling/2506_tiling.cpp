#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

#define man 10000

int main()
{
	int N = 0;
	int arr[250] = {0};
	string n[250];
	string k;
	string ttt;
	long tmp;
	int carr = 0;
	int sz = 0;
	char t[5];	
	cin>>N;

	arr[0] = 1;
	n[0] = "0";
	n[1] = "1";

	for(int i = 2; i<=N; i++)
	{
		arr[i-1] = n[i-1].size()%4;
		if(arr[i-1] != 0){
			for(int l = 0; l<(4-arr[i-1]);l++)
				n[i-1].insert(0,"0");
		}
		if(i%2==0){		
			sz = n[i-1].size()/4;
			for(int j = sz; j >0; j--)
			{
				
					k = n[i-1].substr(4*(j-1),4);
					tmp = atoi(k.c_str());

					tmp = tmp*2 + carr;

					if(j==sz){
						tmp += 1;
					}
					
					if(tmp > man)
						carr = tmp/man;
					else
						carr = 0;

						tmp  %= man;
						itoa(tmp,t,10);
						ttt = t;
						
						n[i].insert(0,t);
					if(i !=N){
						for(int h = 0; h<(4-ttt.size());h++)
							n[i].insert(0,"0");
					}

					if(j==1 && carr >0)
					{
						itoa(carr,t,10);
						n[i].insert(0,t);
					}
				
			}
			
		}
		else {
			sz = n[i-1].size()/4;
			for(int j = sz; j >0; j--)
			{
				
					k = n[i-1].substr(4*(j-1),4);
					tmp = atoi(k.c_str());
					tmp = tmp*2 + carr;

					if(j==sz){
						tmp -= 1;
					}
					if(tmp > man)
						carr = tmp/man;
					else
						carr = 0;

					tmp  %= man;
					itoa(tmp,t,10);
					ttt = t;
						
					n[i].insert(0,t);
					if(i !=N){
						for(int h = 0; h<(4-ttt.size());h++)
								n[i].insert(0,"0");
					}
					if(j==1 && carr >0)
					{
						itoa(carr,t,10);
						n[i].insert(0,t);
					}
					
				
			}
		}
		carr = 0;
	}


		cout<<n[N]<<endl;
	return 0;
}