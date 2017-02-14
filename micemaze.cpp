#include<bits/stdc++.h>
using namespace std;
struct val{
int d;
int w;
};
vector<val>graph[100005];
int src,des,v,timer;
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

void dijakstra()
{
    priority_queue<val,vector<val>,compare >ans;
    //priority_queue<val>ans;
    int dis[105];
    int vis[105];
    for(int i=0;i<105;i++)
		vis[i] = 0;
    for(int i=0;i<105;i++)
		dis[i] = INT_MAX;
	dis[src] = 0;
    val q;
    q.d = src;
    q.w = 0;
    ans.push(q);
    while(!ans.empty())
	{
		q = ans.top();
		ans.pop();
		//cout<<q.d<<endl;
	    if(vis[q.d]==1)
			continue;
		else
			vis[q.d]=1;
		vector<val>::iterator itr = graph[q.d].begin();
		for(;itr!=graph[q.d].end();++itr)
		{
			val s = *itr;
            if(dis[q.d] + s.w < dis[s.d])
			{
                dis[s.d] = dis[q.d] + s.w;
                val t;
                t.d = s.d;
                t.w = dis[s.d];
                ans.push(t);
			}
			//if(dis[q.d] + )
		}
	}
	//for(int i=1;i<=v;i++)
	int sum = 0;
	for(int i=1;i<=v;i++)
	{
		if(dis[i] <= timer)
			sum++;
	}
	cout<<sum<<endl;
}
int main()
{
	int t;
	//cin>>t;
	//while(t--)
	{
		int i,j,k,m,w;
		for(i=0;i<105;i++)
			graph[i].clear();
		int n,e;
		cin>>v>>src>>timer>>e;
		for(j=0;j<e;j++){
		cin>>m>>n>>w;
        val a;
        a.d = m;
        a.w = w;
        graph[n].push_back(a);
		}
		dijakstra();
	}

}
