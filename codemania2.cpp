#include<bits/stdc++.h>
using namespace std;
int a[100005];
int par[100005];
long long int sum = 0;
int root(int i)
{
	return i==par[i] ?  i :  par[i] = root(par[i]);
}
void mer(int j,int k)
{
	if((j = root(j)) ==( k=root(k)))
		return;
	//cout<<j<<" "<<k<<endl;
	if(a[j] < a[k])
		swap(j,k);
	//cout<<a[j]<<" "<<a[k]<<endl;
	sum -= a[k];
	par[k] = j;


}
int main()
{
	int n,k;
	cin>>n>>k;
	int i,j;
	//long long int sum = 0;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		sum += a[i];
	for(i=1;i<=n;i++)
		par[i] = i;
    while(k--)
	{
		int q,l,r;
		cin>>q;
		if(q==1)
		{
			cin>>l>>r;
			mer(l,r);
		}
		else
		{
			cout<<sum<<endl;
			//print
		}
	}
}
