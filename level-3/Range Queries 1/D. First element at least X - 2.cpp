
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gb=-1;
void build_tree(ll int *a, ll int s,ll int e, ll int *tree, ll int index)
{
	if(s==e)
	{
		tree[index] = a[s];
		return;
	}
	ll int mid = (s+e)/2;
	build_tree(a,s,mid,tree,2*index);
	build_tree(a,mid+1,e,tree,2*index+1);
	tree[index] = max(tree[2*index],tree[2*index+1]);
	return;
}
void query(ll int *tree,ll int ss,ll int se,ll x ,ll l ,ll int index)
{
	//complete overlap
	
	if(tree[index]<x)
	return;
	if(gb>=0||se<l)   // just add one extra condition as compare to "First element at least X" (previous problem)
	return;
	if(ss==se)
	{
		if(tree[index]>=x)
		gb=ss;
		return;
	}
	ll int mid = (ss + se)/2;
	 query(tree,ss,mid,x,l,2*index);
	 query(tree,mid+1,se,x,l,2*index+1);
	 return;

}
//point update
void point_update(ll int *tree, ll int ss,ll int se, ll int i,ll int inc,ll int index)
{
	if(i>se || i<ss)
	return;
	if(ss == se)
	{
		tree[index] = inc;
		return;
	}
	ll int mid = (ss + se)/2;
	point_update(tree,ss,mid,i,inc,2*index);
	point_update(tree,mid+1,se,i,inc,2*index+1);
	tree[index] = max(tree[2*index],tree[2*index+1]);
	return;
}

void solve()
{
	int n,q;
	cin>>n>>q;
	
	ll a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	ll tree[4*n+1]={0};
	build_tree(a,0,n-1,tree,1);

	while(q--)
	{
		ll num,l,r;
		cin>>num>>l>>r;
		if(num==1)
		{
			point_update(tree,0,n-1,l,r,1);
			
		}
		else
		{
			gb=-1;
			query(tree,0,n-1,l,r,1);
			cout<<gb<<endl;
		}
		
	}

}
int main()
{
	ios_base::sync_with_stdio(false); 
    	cin.tie(NULL); 
	
    // int src[101]={0};
    // int dest[101]={0};
  
    ll int t=1;
	 // cin>>t;
	while(t--)
	{  
      solve();
    }

return 0;
}
