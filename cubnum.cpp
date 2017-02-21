#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int i,j,k;
	a[0] = 0;
	a[1] = 1;
    for(i=2;i<=100005;i++)
	{
        j = 1;
        a[i] = i;
        for(;j*j*j<=i;j++)
		{
			a[i] = min(a[i],a[i-j*j*j]+1);
		}
	}
	int n,t=1;;
	while(scanf("%d",&n)!=EOF)
	{
		printf("Case #%d: %d\n",t,a[n]);
        t++;
	}
	return 0;

}
