#include<bits/stdc++.h>
using namespace std;
stack<int>val;
int main(){

int t;
cin>>t;
string str;
for(int v=1;v<=t;v++)
{
	cin>>str;
	int i,j,k;
    while(!val.empty())
		val.pop();
	for(i=0;str[i]!='\0';i++)
	{
        val.push(str[i]-'0');
        int a = -1;
        int b = -1;
        int c = -1;
        if(!val.empty())
		{
			a = val.top();
			val.pop();
		}
		if(!val.empty())
		{
			b = val.top();
			val.pop();
		}
		if(!val.empty())
		{
			c = val.top();
			val.pop();
		}
		if(a==0 && b==0 && c==1)
			continue;
		if(c!=-1)
			val.push(c);
		if(b!=-1)
			val.push(b);
		if(a!=-1)
			val.push(a);
	}
	cout<<"Case "<<v<<": ";
	if(!val.empty())
		cout<<"no\n";
	else
		cout<<"yes\n";

}

}
