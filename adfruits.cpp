#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
int main()
{
	while(!cin.eof()){

			string a,b;
			cin>>a>>b;
			//cout<<a<<endl;
			//cout<<b<<endl;
			memset(dp,0,sizeof(dp));
			int i,j,k;
			for(i=0;i<105;i++)
			{
				dp[i][0] = 0;
				dp[0][i] = 0;
			}

			for(i=1;i<=a.length();i++)
			{
				for(j=1;j<=b.length();j++)
				{
					if(a[i-1]==b[j-1])
						dp[i][j] = 1 + dp[i-1][j-1];
					else
						dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
					//cout<<dp[i][j]<<" ";
				}
				//cout<<endl;
			}
			int val = dp[i-1][j-1];
			i--;
			j--;
			stack<char>ans;
			while(i && j)
			{
                if(a[i-1] == b[j-1])
				{

					ans.push(a[i-1]);
					i--;
					j--;
				}
				else
				{
					if(dp[i][j-1] >= dp[i-1][j])
					{
						ans.push(b[j-1]);
						j--;

					}
					else
					{
						ans.push(a[i-1]);
						i--;
					}
				}
			}
			while(i)
			{
				ans.push(a[i-1]);
				i--;
			}
			while(j)
			{
				ans.push(b[j-1]);
				j--;
			}
			while(!ans.empty())
			{
				cout<<ans.top();
				ans.pop();
			}
			cout<<endl;


	}

}
