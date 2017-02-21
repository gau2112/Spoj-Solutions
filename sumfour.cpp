#include<bits/stdc++.h>
using namespace std;
int a[4000];
int b[4000];
int c[4000];
int d[4000];
int v1[4000*4000];
int v2[4000*4000];
int n;
int ubound(int val,int n)
{
	int st = 0;
	int en = n-1;
	int mid = (st+en)/2;
	if(a[en]==val)
		return en;
	while(st <= en)
	{
		//cout<<mid<<endl;
		mid = (st+en)/2;
		if(v2[mid]==val && v2[mid+1]!=val)
			return mid;
		if(v2[mid] > val)
		{
			en = mid - 1;
		}
		else if(v2[mid] < val)
		{
			st = mid + 1;
		}
		else if(v2[mid] == val)
		{
			st = mid + 1;
		}

	}
	return -1;

}
int lbound(int val,int n)
{
	int st = 0;
	int en = n-1;
	int mid = (st+en)/2;
	if(a[st]==val)
		return st;
	while(st <= en)
	{
		mid = (st+en)/2;
		if(v2[mid]==val && v2[mid-1]!=val)
			return mid;
		if(v2[mid] > val)
		{
			en = mid - 1;
		}
		else if(v2[mid] < val)
		{
			st = mid + 1;
		}
		else if(v2[mid] == val)
		{
			en = mid - 1;
		}

	}
	return -1;

}
int main()
{
	int i,j,val;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	}
	int k = 0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			v1[k] = a[i]+b[j];
			v2[k] = c[i]+d[j];
			k++;
		}
	}
	sort(v1,v1+k);
	sort(v2,v2+k);
	/*for(i=0;i<k;i++)
		cout<<v1[i]<<" ";
	cout<<endl;
	for(i=0;i<k;i++)
		cout<<v2[i]<<" ";
	int sum = 0;
	for(i=0;i<k;i++)
		for(j=0;j<k;j++)
		if(v1[i]==v2[j])
		cout<<v1[i]<<endl;
	*/
	long long int ans = 0;
	i=0,j=k-1;
    int freq1=1,freq2=1;

    while(i<k && j>=0)
    {
        long long sum=v1[i]+v2[j];
        while(i+1<k && v1[i]==v1[i+1]) freq1++, i++;
        while(j-1>=0 && v2[j]==v2[j-1]) freq2++ , j-- ;

        if(sum==0)
            ans+=(long long)freq1*(long long)freq2,i++,j--,freq1=1,freq2=1;
        else if(sum>0)
            j-- , freq2=1;
        else i++, freq1=1;;
    }
	cout<<ans<<endl;
}
