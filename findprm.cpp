#include<bits/stdc++.h>
using namespace std;
int a[10000005];
vector<int>pr;
int main()
{
	int t,i,j,k;
	for(i=2;i*i<10000003;i++)
	{
		if(a[i])
			continue;
		for(j=i*i;j<10000003;j+=i)
			a[j] = 1;
	}
	for(i=2;i<=10000001;i++)
		if(!a[i])
			pr.push_back(i);
	scanf("%d",&t);
	//cin>>t;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int sum =0 ;
		if(n==2 || n==3)
		{
			printf("%d\n",n-1);
			continue;
		}
		vector<int>::iterator it1,it2;
		it1 = lower_bound(pr.begin(),pr.end(),n/2);
		it2 = lower_bound(pr.begin(),pr.end(),n);
        if(a[n]!=0)
			--it2;
		if(a[n/2]!=0)
			--it1;
		int v1 = it1 - pr.begin();
		int v2 = it2 - pr.begin();
		printf("%d\n",v2-v1);
	}

}
