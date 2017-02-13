/* The Shortest Path Spoj Solution*/
#include<bits/stdc++.h>
using namespace std;
struct val{
int d;
int w;
};
vector<val>graph[100005];
map<string,int>city;
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

void dijakstra()
{
    priority_queue<val,vector<val>,compare >ans;
    //priority_queue<val>ans;
    int dis[100005];
    int vis[100005];
    for(int i=0;i<100005;i++)
		vis[i] = 0;
    for(int i=0;i<100005;i++)
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
	    if(q.d == des)
			break;
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
	if(dis[des]!=INT_MAX)
	cout<<dis[des]<<endl;
	else
		cout<<"NO\n";
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i,j,k,m,w;
		int cnos = 0;
		for(i=0;i<100005;i++)
			graph[i].clear();
		int n,e;
		cin>>v;
		for(j=1;j<=v;j++){
	    string ci;
	    cin>>ci;
	    city[ci] = j;
        cin>>e;
        for(i=0;i<e;i++)
		{
			val query;
			cin>>query.d>>query.w;
			graph[j].push_back(query);
		}
		}
		int u;
		cin>>u;
		while(u--)
		{
            string p,q;
            cin>>p>>q;
            src = city[p];
            des = city[q];
            dijakstra();
		}
		//cin>>src>>des;
		//dijakstra();
	}

}
