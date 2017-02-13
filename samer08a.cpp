/*Almost Shortest Path*/
#include<bits/stdc++.h>
using namespace std;
struct val{
int d;
int w;
};
long long int graph[505][505];
int src,des,v;
class compare{

public:
bool operator()(const val& p,const val& q)
{
	return p.w > q.w;
}
};

bool operator<(const val& p,const val& q)
{
	return p.w > q.w;
}
int first;
void update(int par[],int dis[])
{

	int i = des,j;
	while(par[i] != -2)
	{
		j = par[i];
		//cout<<i<<" "<<j<<endl;
		graph[j][i] = INT_MAX;
		//cout<<i<<" "<<j<<endl;
		dis[i] = INT_MAX;
		i = j;
	}
}
int updated_dijakstra()
{
	priority_queue<val,vector<val>,compare >ans;
    //priority_queue<val>ans;
    int dis[505];
    int vis[505];
    int par[505];
    for(int i=0;i<505;i++)
		vis[i] = 0;
    for(int i=0;i<505;i++)
		par[i] = -1;
    for(int i=0;i<505;i++)
		dis[i] = INT_MAX;
	dis[src] = 0;
	par[src] = -2;
    val q;
    q.d = src;
    q.w = 0;
    ans.push(q);
    while(!ans.empty())
	{
		q = ans.top();
		ans.pop();
		//cout<<q.d<<endl;
	    if(q.d == des)
		{
            //cout<<dis[des]<<endl;
            break;
		}
	    //vector<val>::iterator itr = graph[q.d].begin();
        int p = q.d;
        for(int i=0;i<v;i++)
		{
			if(graph[p][i]!=INT_MAX)
			if(dis[p] + graph[p][i] < dis[i])
			{
					dis[i] =  dis[p] + graph[p][i];
					par[i] = p;
					val pot;
					pot.d = i;
					pot.w = dis[i];
					ans.push(pot);
				}
		}
	}

	if(dis[des]== INT_MAX)
	dis[des] = -1;
	return dis[des];

}
bool dfs(int is,int res)
{
	if(is==des && res==0)
	{
		//graph[is][d] = INT_MAX;
		return true;
	}
	if(res < 0)
		return false;
	if(is==des)
	{
		return false;
	}
	int i=0;
	int flag = 0;
	for(i=0;i<v;i++)
	{
		if(graph[is][i]!=INT_MAX)
		{
			if(dfs(i,res-graph[is][i])==true)
			{
				graph[is][i] = INT_MAX;
				flag = 1;//return true;
			}

		}
	}
	if(flag)
		return true;
	return false;

}
int main()
{
	int t;
	//cin>>t;
	while(1)
	{
		first = -1;
		int i,j,k,m,w;
		int n,e;
		for(i=0;i<505;i++)
			for(j=0;j<505;j++)
			graph[i][j] = INT_MAX;
		cin>>v>>e;
		if(v==0 && e==0)
			break;
		cin>>src>>des;
		for(i=1;i<=e;i++)
		{
			int s,d,w;
			cin>>s>>d>>w;
			graph[s][d] = w;
		}
		int res = updated_dijakstra();
		if(res==-1)
		{
			cout<<"-1\n";
			continue;
		}
		dfs(src,res);
		res = updated_dijakstra();
		cout<<res<<endl;

		//cin>>src>>des;
		//dijakstra();
	}

}
