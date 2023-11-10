
#include<bits/stdc++.h>
using namespace std;
#define ll long long

//Build Segment Tree
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
	tree[index] += tree[2*index]+tree[2*index+1];
	return;
}

//Query
ll query(ll *tree,ll ss,ll se,ll qs,ll qe ,ll index)
{
	//complete overlap
	if(ss>=qs and se<=qe)
	{
		return tree[index];
	}
	//No Overlap
	if(qe<ss || qs>se)
	return 0;

	//partial overlap
	ll int mid = (ss + se)/2;
	ll int left = query(tree,ss,mid,qs,qe,2*index);
	ll int right = query(tree,mid+1,se,qs,qe,2*index+1);
	return left+right;
}

//point update
void point_update(ll  *tree, ll ss,ll se, ll i,ll inc,ll index)
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
	tree[index] = tree[2*index]+tree[2*index+1];
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

	
	while(q--) {
		ll num,l,r; cin>>num>>l>>r;
		if(num == 1) {
			point_update(tree,0,n-1,l,r,1);
		}
		else cout<<query(tree,0,n-1,l,r-1,1)<<endl;
		
	}

}
int main()
{
	ios_base::sync_with_stdio(false); 
    	cin.tie(NULL);
  
    ll int t=1;
	 // cin>>t;
	while(t--)
	{  
      solve();
    }

	return 0;
}
