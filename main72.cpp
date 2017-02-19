#include<bits/stdc++.h>
using namespace std;
int dp[2][100004];
int v[105];
int a[105];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		memset(v,0,sizeof(v));
        int i,j,k,n,sum=0;
        cin>>n;
        for(i=1;i<=n;i++)
        {
        	cin>>a[i];
        	sum += a[i];
        }

        for(i=0;i<=sum;i++)
			dp[0][i] = 0;
		dp[0][0] = 1;
		dp[1][0] = 1;
		for(i=1;i<=n;i++)
		{
			int q = i%2;
			int s = q^1;
			for(j=1;j<=sum;j++)
			{
				if(a[i]>j)
				{

					dp[q][j] = dp[s][j];
					//continue;
				}
				else
				dp[q][j] = dp[s][j-a[i]] | dp[s][j];

				//if(i==2 && j==3)
				//	//cout<<dp[1][0]<<endl;
				//cout<<dp[i][j]<<" ";
				//dp[i][j]

			}
			//v[a[i]] = 1;
			//cout<<endl;
		}
		int s = 0;
		int res = n%2;
		for(i=0;i<=sum;i++)
		{
			if(dp[res][i])
				s += i;//<<dp[1][i]<<endl;

		}
		cout<<s<<endl;

	}
}
