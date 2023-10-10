#include<bits/stdc++.h>
using namespace std;
int n,p,a,c;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(a==0)
		{
			c++;
			p=0;
		}
		else if(p==0)
		{
			if(a==1)
				p=1;
			else if(a==2)
				p=2;
		}
		else if(p==1)
		{
			if(a==1)
			{
				p=0;
				c++;
			}
			else
				p=2;
		}
		else
		{
			if(a==2)
			{
				p=0;
				c++;
			}
			else
				p=1;
		}
	}
	cout<<c;
	return 0;
}