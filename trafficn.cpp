#include<bits/stdc++.h>
#define infi 1061109567
#define VERTICES 10005
#define gc getchar_unlocked

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}


using namespace std;
struct val{
int d;
int w;
};
vector<val>graph[VERTICES];
vector<val>invgraph[VERTICES];
int dis[VERTICES];
int invdis[VERTICES];
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
/*
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
*/
void dijakstra(vector<val>graph[],int dis[],int src)
{
	priority_queue<val,vector<val>,compare >ans;
    //priority_queue<val>ans;
    //int dis[505];
    int vis[VERTICES];
    //int par[505];
    for(int i=0;i<VERTICES;i++)
		vis[i] = 0;
    dis[src] = 0;
	val q;
    q.d = src;
    q.w = 0;
    ans.push(q);
    while(!ans.empty())
	{
		q = ans.top();
		ans.pop();
		if(vis[q.d]==1)
			continue;
		vis[q.d] = 1;
		//cout<<q.d<<endl;
	    vector<val>::iterator itr = graph[q.d].begin();
        int p = q.d;
        for(;itr!=graph[q.d].end();++itr)
		{
            val b = *itr;
            if(dis[p]!=infi && dis[p] + b.w < dis[b.d])
			{
                dis[b.d] = dis[p] + b.w;
                val pot;
                pot.d  = b.d;
                pot.w = dis[b.d];
                ans.push(pot);
			}
		}
        /*for(int i=0;i<v;i++)
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
		}*/
	}
}


/*
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
*/
int main()
{
	int t;
	scanint(t);
	//scanf("%d",&t);
	//cin>>t;
	while(t--)
	{
        int i,j;
		for(i=0;i<VERTICES;i++)
		{
			dis[i] 	  = infi;
			graph[i].clear();
			invgraph[i].clear();
			invdis[i] = infi;
		}
		int v,e,k,src,des;
		scanint(v);
		scanint(e);
		scanint(k);
		scanint(src);
		scanint(des);
		//scanf("%d%d%d%d%d",&v,&e,&k,&src,&des);
		//cin>>v>>e>>k>>src>>des;
		for(i=1;i<=e;i++)
		{
			int s,d,w;
			val a,b;
			scanint(s);
			scanint(d);
			scanint(w);
			//cin>>s>>d>>w;
			a.d = d;
			a.w = w;
			b.d = s;
			b.w = w;
			graph[s].push_back(a);
			invgraph[d].push_back(b);
		}
		dijakstra(graph,dis,src);
		dijakstra(invgraph,invdis,des);
		/*
		for(i=1;i<=v;i++)
			cout<<dis[i]<<" ";
		cout<<endl;
		for(i=1;i<=v;i++)
			cout<<invdis[i]<<" ";
		cout<<endl;
		*/
		int mini = min(dis[des],invdis[src]);
		for(i=1;i<=k;i++)
		{
            int s,d,w;
            scanint(s);
			scanint(d);
			scanint(w);

            //cin>>s>>d>>w;
            int r1 = dis[s] + w + invdis[d];
            int r2 = dis[d] + w + invdis[s];
            mini = min(mini,r1);
            mini = min(mini,r2);
		}
		if(mini == infi)
			mini = -1;
		printf("%d\n",mini);
		//cout<<mini<<endl;

		//cin>>src>>des;
		//dijakstra();
	}

}
