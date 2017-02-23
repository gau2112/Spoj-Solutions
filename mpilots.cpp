#include<bits/stdc++.h>
using namespace std;
struct q{

int t;
int p;

}a[10005];
int dp[5005][5005];
int n;
int call(int in,int ac,int pc)
{
    if(dp[ac][pc]!=-1)
		return dp[ac][pc];
    if(in==n)
		return 0;
	if(in==n-1)
	{
			dp[ac][pc] = a[in].p;
			return a[in].p;
	}
	if(ac == n/2)
	{
		dp[ac][pc] = a[in].p + call(in+1,ac,pc+1);
		return dp[ac][pc];
	}
	if(ac==pc)
	{
			dp[ac][pc] = a[in].t + call(in+1,ac+1,pc);
			return dp[ac][pc];
	}
	dp[ac][pc] =  min(a[in].t + call(in+1,ac+1,pc),a[in].p + call(in+1,ac,pc+1));
	return dp[ac][pc];
}
int main()
{
	//int n;
	memset(dp,-1,sizeof(dp));
	cin>>n;
	int i,j,k;
	for(i=0;i<n;i++)
		cin>>a[i].p>>a[i].t;
    int res = a[0].t + call(1,1,0);
    cout<<res<<endl;
    return 0;
}
