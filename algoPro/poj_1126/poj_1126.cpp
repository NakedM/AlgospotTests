#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string str;
int size = 0;
int rst;
int cnt= 0;

bool corrSen(int i){
	bool a = false,b = false;

	if(i>=size)
		return false;
	
	if(str[i] == 'N')
	{
		cnt++;
		return corrSen(i+1);
	}
	else if(str[i] == 'C' || str[i] == 'D' || str[i] == 'E' || str[i] == 'I' )
	{
		cnt++;
		a = corrSen(i+1);
		cnt++;
		b = corrSen(cnt-1);
		return a & b;
	}
	else if(str[i]>='p' && str[i]<='z')
	{			
		return true;
	}
	else
		return false;
}
int main(){
	
	bool rst;
	
	while(cin>>str)
	{
		size = str.length();
		cnt= 1;
		rst = false;

		rst = corrSen(0);

		if(rst && (cnt==size))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
