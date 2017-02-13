#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int b[11000000];
vector<int>primes;
vector<int>sols;
int main()
{
	int t;
	//cin>>t;
	int i,j;
	a[0]=1;
	a[1]=1;
	for(i=2;i*i<5300000;i++)
	{
		if(a[i])
			continue;
		for(j=i*i;j<5300000;j+=i)
			a[j] = 1;
	}
	for(i=2;i<5300000;i++)
		if(!a[i])
		primes.push_back(i);
	vector<int>::iterator itr = primes.begin();
	for(;itr!=primes.end();++itr)
	{
		int k = *itr;
		for(j=*itr;j<11000000;j+=k)
			{
				if(a[j/k]==0)
					b[j]++;
				//if(a[j/(*itr)];
			}
	}
	for(i=4;i<11000000;i++)
		if(b[i]==2)
		{
			sols.push_back(i);
			if(sols.size()==2000000)
			{
				//cout<<"found"<<i<<endl;
				break;
			}
		}
	//cout<<sols.size()<<endl;
	//cout<<sols[0]<<endl;
	cin>>t;
	while(t--)
	{
		int i,n,j,k;
		cin>>n;
		cout<<sols[n-1]<<endl;
	}
}
