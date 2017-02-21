#include<bits/stdc++.h>
using namespace std;
string a;
int dp[6105][6105];
int call(int i,int j)
{
	//cout<<"*";
	if(dp[i+1][j+1]!=INT_MAX)
		return dp[i+1][j+1];
	if(i>=a.length())
		{
			dp[i+1][j+1] = j+1;
			return dp[i+1][j+1];
		}
	if(j<0)
		{
			dp[i+1][j+1] = a.length() - i;
			return dp[i+1][j+1];
		}
	if(a[i]==a[j])
	{
		dp[i+1][j+1] = call(i+1,j-1);
	}
	else
	dp[i+1][j+1] = 1+min(call(i,j-1),call(i+1,j));
	return dp[i+1][j+1];

}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>a;
		int i,j;
		for(i=0;i<6105;i++)
		{
			for(j=0;j<6105;j++)
				dp[i][j] = INT_MAX;
		}
		int q = INT_MAX;
		int n=INT_MAX;
		int m=INT_MAX;
		for(int i=0;a[i]!='\0';i++)
		{

			if(i<a.length()-1 && a[i]==a[i+1])
				n = call(i+2,i-1);
			m = call(i+1,i-1);
			//cout<<i<<" "<<m<<" "<<n<<endl;
			q = min(q,m);
			q = min(q,n);

		}
		//q = min(q,n);
		cout<<q<<endl;
	}
}
