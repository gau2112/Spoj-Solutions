#include<bits/stdc++.h>
using namespace std;
long long int a[1005];
long long int sum[1005];
int main()
{
    int t;
    cin>>t;
    while(t--)
	{
		memset(sum,0,sizeof(sum));
		int n;
		cin>>n;
		int i,j;
		for(i=1;i<=n;i++)
			cin>>a[i];
		for(i=1;i<=n;i++)
			{
				sum[i] = sum[i-1];
				sum[i] += a[i];
			}
        long long int mini = INT_MAX;
        for(i=1;i<=n;i++)
		{
			if(sum[i] < mini)
				mini = sum[i];
		}
		if(mini <= 0)
		{
			long long int val = 1;
			val -=  mini;
			cout<<val<<endl;
		}
		else{
			cout<<"0\n";
		}

	}
}
