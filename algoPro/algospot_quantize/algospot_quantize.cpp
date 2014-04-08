#include<iostream>
#include<algorithm>
#include<cmath>

#define INF 987654321
using namespace std;

int n,s;
int arr[101];
int subsum[101];
int sqsum[101];
int cache[110][15];


int cal(int a, int k){
	int rst,rst2;
	int ssum =0 ;
	int qsum = 0;
	int average = 0;

	ssum = subsum[k] - (a==0? 0 : subsum[a-1]);
	qsum = sqsum[k] - (a==0? 0 : sqsum[a-1]);

	average = int((float)ssum/(k-a+1) + 0.5);		
	rst = qsum -2*ssum*average + average*average*(k-a+1);
	rst2 = qsum -2*ssum*(average+1) + (average+1)*(average+1)*(k-a+1);

	return min(rst,rst2);
}

int divider(int a, int dcnt){
	int& sm = cache[a][dcnt];

	if(sm != -1)
			return sm;

	if(dcnt == 0)
		return sm = cal(a,n-1);

	sm = INF;
	for(int k=a;k<n-dcnt;k++){		
			sm = min(sm,(cal(a,k)+divider(k+1,dcnt-1)));		
	}	
	return sm;
}
int main(){
	int tc;
	cin>>tc;
	
	while(tc--)
	{
		cin>>n>>s;
		
		for(int i=0;i<101;i++){
			arr[i] = 0;
			subsum[i] = 0;
			sqsum[i] = 0;
		}
		for(int i=0;i<110;i++){
			for(int j=0;j<15;j++){
				cache[i][j] = -1;
			}
		}
		for(int i=0;i<n;i++)
			cin>>arr[i];

		sort(arr,arr+n);

		if(s>=n)
		{
			cout<<0<<endl;
			return 0;
		}

		subsum[0] = arr[0];
		sqsum[0] = arr[0]*arr[0];
		for(int i=1;i<n;i++){
			subsum[i] = subsum[i-1] + arr[i];
			sqsum[i] = sqsum[i-1] + arr[i]*arr[i];
		}
		cout<<divider(0,s-1)<<endl;
		
	}
	return 0;
}

/*
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <stack>
#include <queue>
#include <map>
#include <ctime>

using namespace std;

#define WT while(true)
#define REP(v, hi) for (int v=0;v<(hi);v++)
#define REPD(v, hi) for (int v=((hi)-1);v>=0;v--)
#define FOR(v, lo, hi) for (int v=(lo);v<(hi);v++)
#define FORD(v, lo, hi) for (int v=((hi)-1);v>=(lo);v--)

int cnt, s;
int num[110], sum[110], sum2[110];
int dp[13][110];

//num[]에서 [a, b] 범위의 오차최소값을 반환
int get_minn(int a, int b){
	int summ = (a==0?sum[b]:sum[b]-sum[a-1]);
	int summ2 = (a==0?sum2[b]:sum2[b]-sum2[a-1]);
	int avg = summ/(b-a+1);
	return min(summ2-summ*2*avg+(b-a+1)*avg*avg, summ2-summ*2*(avg+1)+(b-a+1)*(avg+1)*(avg+1));
}

//index 부터 끝까지 sizee 만큼의 분할의 오차제곱의 최소값을 반환
int req(int sizee, int index){
	int& ret = dp[sizee][index];
	if (ret!=-1)  return ret;
	if (sizee==1) return (ret=get_minn(index, cnt-1));
	ret = 999999999;
	FOR(i, index, cnt-sizee+1) ret = min(ret, get_minn(index, i) + req(sizee-1, i+1));
	return ret;
}

int main(){
	int t;

	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &cnt, &s);
		s = min(cnt, s);
		REP(i, 13) REP(j, 110) dp[i][j] = -1;
		REP(i, cnt) scanf("%d", &num[i]);
		sort(&num[0], &num[cnt]);

		sum[0] = num[0];
		sum2[0] = num[0]*num[0];
		FOR(i, 1, cnt) sum[i] = sum[i-1] + num[i];
		FOR(i, 1, cnt) sum2[i] = sum2[i-1] + num[i]*num[i];
		printf("%d\n", req(s, 0));
	}//while
	return 0;
}

*/