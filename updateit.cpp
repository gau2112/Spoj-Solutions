#include<bits/stdc++.h>
#define gc getchar_unlocked

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}


using namespace std;
int a[10005];
int main()
{
	int t;
	scanint(t);
	//cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		int n,m,q;
		scanint(n);
		scanint(q);
		//cin>>n>>q;
		int i,j;
		while(q--)
		{
			int l,r,v;
			scanint(l);
			scanint(r);
			scanint(v);
			//cin>>l>>r>>v;
			a[l] += v;
			a[r+1] -= v;
		}
		for(i=1;i<n;i++)
			a[i] += a[i-1];
		scanint(q);
		//cin>>q;
		while(q--)
		{
			int val;
			scanint(val);
			//cin>>val;
			printf("%d\n",a[val]);
			//cout<<a[val]<<endl;
		}
	}
	return 0;
}
