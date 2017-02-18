#include<bits/stdc++.h>
using namespace std;
int dp[100005][3];
int a[100005][3];
int main()
{
	int t=0;
	while(1)
	{
		++t;
		memset(dp,0,sizeof(dp));
        int n,i,j;
        cin>>n;
        if(n==0)
			break;
        for(i=0;i<n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];//<<endl;
		}
		dp[0][0] = a[0][1] + 1;
		dp[0][1] = a[0][1];
		dp[0][2] = dp[0][1] + a[0][2];
		for(i=1;i<n;i++)
		{
			dp[i][0] = INT_MAX;
			dp[i][1] = INT_MAX;
			dp[i][2] = INT_MAX;
			int v1 = min(dp[i-1][0],dp[i-1][1]);
			int v2 = min(v1,dp[i-1][2]);
			int v3 = min(dp[i-1][1],dp[i-1][2]);
			dp[i][0] = min(dp[i][0],v1 + a[i][0]);
			dp[i][1] = min(dp[i][1],v2+a[i][1]);
			dp[i][1] = min(dp[i][1],dp[i][0] + a[i][1]);
			dp[i][2] = min(dp[i][2],v3+a[i][2]);
			dp[i][2] = min(dp[i][2],dp[i][1] + a[i][2]);
		}
		cout<<t<<". "<<dp[n-1][1]<<endl;

	}
}
