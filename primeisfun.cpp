#include<bits/stdc++.h>
using namespace std;
int pr[2005];
int a[2005];
int sum[2005];
int dp[2005];
vector<int>primes;
int main()
{
	int i,j,k;
	pr[0] = 1;
	pr[1] = 1;
	for(i=2;i*i<2005;i++)
	{
		if(pr[i])
			continue;
		for(j=i*i;j<2005;j+=i)
			pr[j] = 1;
	}
	for(i=2;i<=2004;i++)
	{
		if(!pr[i])
			primes.push_back(i);
	}
	int t;
	cin>>t;
	while(t--)
	{
        //maxi = -1;
        int n;
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(i=1;i<=n;i++)
			cin>>a[i];
		dp[0] = 0;
		dp[1] = 0;
		sum[1] = a[1];
		for(i=2;i<=n;i++)
			sum[i] = sum[i-1] + a[i];
		for(i=1;i<=n;i++)
			if(!pr[i])
			dp[i] = sum[i];
		for(i=2;i<=n;i++)
		{
			if(pr[i])
			{
                vector<int>::iterator itr = primes.begin();
                dp[i] = dp[i-1];
                for(;*itr <= i;++itr)
				{
					int v = *itr;
					dp[i] = max(dp[i],dp[i-v-1] + sum[i] - sum[i-v]);
				}
			}
		}
		long long int sum = 0;
		//for(i=1;i<=n;i++)
		//sum = max(sum,dp[i]);
		cout<<dp[n]<<endl;
	}

}
