#include<bits/stdc++.h>
#define lim 1000004
using namespace std;
int a[1000005];
vector<int>pr;
struct point{
int prime;
int product;

};
vector<point>pal;
int check_palin(int i)
{
    int temp = i;
    int rev = 0;
    int val=1;
    while(temp)
	{
		if(temp%10)
			val*=temp%10;
		rev = rev*10 + temp%10;
		temp/=10;
	}
	if(rev==i)
		return val;
	else
		return 0;
}
int main()
{
    int t,i,j,k;
    for(i=2;i*i<lim;i++)
	{
		if(!a[i])
			for(j=i*i;j<lim;j+=i)
				a[j] = 1;
	}
	int maxi = -1;
	for(i=2;i<lim;i++)
		{
			if(!a[i])
		{
			pr.push_back(i);
            int val = check_palin(i);
            maxi = max(maxi,val);
			if(val)
				{
					point p;
					p.prime = i;
					p.product = val;
					pal.push_back(p);
				}

		}
		}
		//cout<<pal.size()<<endl;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        cout<<pal[n-1].prime<<" "<<pr[pal[n-1].product-1]<<endl;
	}
		//cout<<pal.size()<<endl<<maxi<<endl<<pr.size();
}
