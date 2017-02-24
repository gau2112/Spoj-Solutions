#include<bits/stdc++.h>
using namespace std;
int a[10000005];
int b[10000005];
int sp[10000005];
int av[100005];
//vector<int>checks[10000002];
int main()
{
    int i,j;
    for(i=2;i<10000005;i+=2)
		{
			sp[i] = 2;
			a[i] = 1;
		}
	a[2] = 0;
    for(i=3;i<10000005;i+=2)
	{
		if(!a[i])
		{
            sp[i] = i;
            for(j=i;(long long int)j*i<10000005;j+=2)
			{
				if(!a[j*i])
				{
					sp[j*i] = i;
					a[j*i] = 1;

				}
			}
		}
	}
	for(i=3;i<100000;i++)
		if(sp[i] == 0)
		{
			cout<<i<<endl;
			//break;
		}
	//cout<<"!";
    //int k = primes.size();
    /*for(i=0;i<k;i++)
	{
		for(j = primes[i];j<10000001;j+=primes[i])
			checks[j].push_back(primes[i]);
	}*/
	//cout<<"!";
    int t;
    cin>>t;
    while(t--)
	{
		int n,maxi = -1;
		cin>>n;
		memset(b,0,sizeof(b));
		for(i=0;i<n;i++)
			{
				cin>>av[i];
				//maxi = max(maxi,a[i]);
			}
		for(i=0;i<n;i++)
		{
            int j = av[i];
            while(j>1)
			{
                b[sp[j]] = 1;
                j = j/sp[j];

			}
		}

		for(i=2;i<10000003;i++)
		{
			if(!b[i] && !a[i])
			{
				cout<<i<<endl;
				break;
			}
		}

	}
}
