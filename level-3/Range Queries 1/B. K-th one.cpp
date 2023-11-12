
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll glb;
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

ll query(ll *tree,ll ss,ll se,ll & k ,ll index)
{
	if(glb!=-1||tree[index]==0)
	return INT_MAX;

	if(tree[index]<k)
	{
		k -= tree[index];
		return INT_MAX;
	}
	if(ss == se)
	{
		glb = ss;
		return ss;
	}
	//partial overlap
	ll int mid = (ss + se)/2;
	ll int left = query(tree,ss,mid,k,2*index);
	ll int right = query(tree,mid+1,se,k,2*index+1);
	return min(left,right);
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

	// for(int i=1;i<=4*n;i++)
	// cout<<tree[i]<<endl;
	
	while(q--)
	{
		ll num,l;
		cin>>num>>l;
		if(num==1)
		{
			point_update(tree,0,n-1,l,!a[l],1);
			a[l]=!a[l];
		}
		else
		{
		l++;
		glb=-1;
		ll x = query(tree,0,n-1,l,1);
		cout<<x<<endl;
		}
		
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
  


