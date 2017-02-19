#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
	{
		int i,n,c;
		cin>>n>>c;
		for(i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
        int maxi = a[n-1] - a[0];
        int st = 1;
        int en = maxi;
        int mid = maxi;
        int j = c-1;//,i;
        int mark = a[0];
        int ans;
        while(1)
		{
            if(st > en)
				break;
			j=c-1;
			mark = a[0];
            for(i=1;i<n && j>0;i++)
			{
                if(a[i] - mark >= maxi)
				{
					j--;
					mark = a[i];
				}

			}
			//cout<<"1"<<endl;
			if(j==0)
			{
				ans = maxi;
				//cout<<ans<<endl;
				st = maxi+1;
			}
			else
			{
				en = maxi - 1;
			}
			maxi = (st+en)/2;
		}
		cout<<ans<<endl;

	}
	return 0;
}
