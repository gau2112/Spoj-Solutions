#include<bits/stdc++.h>
using namespace std;
int a[5005];
int dp[5005];
int sign[5005];
int main()
{
    int n;
    cin>>n;
    int i,j,k;
    for(i=0;i<n;i++)
	{
		cin>>a[i];
		dp[i] = 1;
		sign[i] = 1;
		if(a[i]<0)
		{
			a[i] = abs(a[i]);
			sign[i] = 0;
		}
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
            if(a[j] < a[i] && sign[j] != sign[i])
				dp[i] = max(dp[i],dp[j]+1);
		}
	}
	int  maxi = -1;
	for(i=0;i<n;i++)
		maxi = max(maxi,dp[i]);
	cout<<maxi<<endl;

}
