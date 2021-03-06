#include<bits/stdc++.h>
using namespace std;
struct val{
int d;
int w;
};
vector<val>graph[100005];
int src,des,v;

// Compare class for the dijakstra's algorithm
// There are two ways
// Method 1
class compare{

public:
bool operator()(const val& p,const val& q)
{
	return p.w > q.w;
}
};

// Method 2
/*
bool operator<(const val& p,const val& q)
{
	return p.w > q.w;
}
*/
void dijakstra()
{
    // Notation 1
    priority_queue<val,vector<val>,compare >ans;
    // Notation 2
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
		for(i=0;i<100005;i++)
			graph[i].clear();
		int n,e;
		cin>>v>>e;
		for(j=0;j<e;j++){
		cin>>m>>n>>w;
        val a;
        a.d = n;
        a.w = w;
        graph[m].push_back(a);
		}
		cin>>src>>des;
		dijakstra();
	}

}
