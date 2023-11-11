
#include <bits/stdc++.h>
using namespace std;
#define 		ll long long
#define         max3(a, b, c) max(max(a, b), c)
struct tre
{
	ll suf,pref,seg,sum;
};
vector<tre>tree(400001);
tre merge(tre a,tre b)
{
	tre t={max(b.suf,b.sum+a.suf),max(a.pref,a.sum+b.pref),max3(a.seg,b.seg,a.suf+b.pref),a.sum+b.sum};
	return t;
}
void build_tree(ll int *a, ll int s,ll int e, ll int index)
{
	if(s==e)
	{
		if(a[s]>0)
		tree[index] = {a[s],a[s],a[s],a[s]};
		else
		tree[index] = {0,0,0,a[s]};
		return;
	}
	ll int mid = (s+e)/2;
	build_tree(a,s,mid,2*index);
	build_tree(a,mid+1,e,2*index+1);
	tree[index] = merge(tree[2*index],tree[2*index+1]);
	return;
}

//point update
void point_update(ll int ss,ll int se, ll i,ll int inc,ll int index)
{
	if(i>se || i<ss)
	return;
	if(ss == se)
	{
		if(inc>0)
		tree[index] = {inc,inc,inc,inc};
		else
		tree[index] = {0,0,0,inc};
		return;
	}
	ll int mid = (ss + se)/2;
	point_update(ss,mid,i,inc,2*index);
	point_update(mid+1,se,i,inc,2*index+1);
	tree[index] = merge(tree[2*index],tree[2*index+1]);
	return;
}



void solve()
{
	int n,q;
	cin>>n>>q;
	
	ll a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	build_tree(a,0,n-1,1);
	// for(int i=1;i<=4*n;i++)
	// cout<<tree[i]<<endl;
	cout<<tree[1].seg<<endl;
	
	while(q--)
	{
		ll num,l;
		cin>>num>>l;
		point_update(0,n-1,num,l,1);
		cout<<tree[1].seg<<endl;
		a[num] = l;
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
