#include<bits/stdc++.h>
using namespace std;
int vis[10005];
int df[10005];
vector<int>a[10005];
int val;
int dfs(int src)//,int nod)
{
    vis[src] = 1;
    //df[src] = 1;
    val++;
    //nod++;
    vector<int>::iterator itr = a[src].begin();
    for(;itr!=a[src].end();++itr)
	{
		if(!vis[*itr])
			 dfs(*itr);
		//else
			//df[src] +=  df[*itr];
	}
	return val;
}
int main()
{
	int n,m;
	cin>>n>>m;
	int i,j,k,l,r;
	for(i=0;i<m;i++)
	{
		cin>>l>>r;
        a[l].push_back(r);
	}
	int res = -1,cnt;//,val;
	for(i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		val = 0;
		cnt = dfs(i);
		res = max(res,cnt);
	}
	//for(i=1;i<=n;i++)
		//cout<<df[i]<<" ";
	cout<<res<<endl;
	return 0;
}
