#include<bits/stdc++.h>
using namespace std;
int a[2005];
int sum[2005],n;
long long int dp[2005][2005];
int call(int s,int e,int age)
{
    if(s>e)
		return 0;
    return max(a[s]*age+call(s+1,e,age+1),a[e]*age+call(s,e-1,age+1));
}
int main()
{
    cin>>n;
    int i,j;
    for(i=1;i<=n;i++)
		cin>>a[i];
	//sum[1] = a[1];
	for(i=1;i<=n;i++)
		{
			sum[i] = a[i] + sum[i-1];
			//cout<<sum[i]<<" ";
		}
		//cout<<endl;

	//cout<<call(1,n,1)<<endl;
	for(i=1;i<=n;i++)
		dp[i][i] = a[i];
		//int age = 1;
	for(i=n-1;i>=1;i--)
	{
		//age++;
		for(j=1;j<=n;j++)
		{
			if(i>=j)
				{
					//cout<<dp[i][j]<<" ";
					continue;
				}
			int age = j-i+1;
			int v1 = a[i];
			int v2 = a[j];
			dp[i][j] = v2 + dp[i][j-1] + (sum[j-1] - sum[i-1]);

			dp[i][j] = max(dp[i][j],v1 + dp[i+1][j] + (sum[j]-sum[i]));
			//cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<v2<<" "<<dp[i][j-1]<<" "<<(sum[j-1])<<" "<<sum[i-1]<<endl;
			//cout<<dp[i][j]<<" ";
		}
		//cout<<endl;
	}
	cout<<dp[1][n]<<endl;

}
