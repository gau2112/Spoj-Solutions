#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
	{
		int i,n,k;
		cin>>n>>k;
		for(i=0;i<n;i++)
			cin>>a[i];
		long long int sum = 0;
        for(i=0;i<n;i++)
		{
            if(a[i]<=k)
				sum += k-a[i];
			else
			{
				sum += min(a[i]%k,k-(a[i]%k));
			}
		}
		cout<<sum<<endl;
	}
}
