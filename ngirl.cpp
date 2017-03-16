#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int a[1000005];
vector<ll>prs;
int main()
{
	int t;
	cin>>t;
	int i,j;//,k,m;
	for(i=2;i*i<1000000;i++)
	{
		if(!a[i])
		for(j=i*i;j<1000000;j+=i)
			a[j]=1;
	}
	ll k;
	//prs.push_back(0);
	for(i=2;i<1000000;i++)
	{
		if(!a[i])
		{
			k = i;
			k *= i;
			prs.push_back(k);
		}
	}
	while(t--)
	{
		long long int n,k;
		cin>>n>>k;
        vector<ll>::iterator it1,it2;
        it1 = upper_bound(prs.begin(),prs.end(),n);
        it2 = upper_bound(prs.begin(),prs.end(),k);
        int ub1 = it1 - prs.begin();
        int ub2 = it2 - prs.begin();
        if(prs[ub1]==n)
			ub1++;
		if(prs[ub2]==k)
			ub2++;
		if(k<n)
		cout<<ub1<<" "<<ub1-ub2<<endl;
		else
			cout<<ub1<<" 0\n";
        //cout<<ub1<<" "<<ub2<<endl;
        //int
	}
}
