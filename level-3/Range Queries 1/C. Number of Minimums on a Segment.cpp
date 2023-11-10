// This is AC solution
#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define ff first

#define ss second

vector<pair<ll, ll>> tree(400001);

void build_tree(ll int *a, ll int s, ll int e, ll int index)
{
  if (s == e)
  {
    tree[index] = {a[s], 1};
    return;
  }
  ll int mid = (s + e) / 2;
  build_tree(a, s, mid, 2 * index);
  build_tree(a, mid + 1, e, 2 * index + 1);

  if (tree[2 * index].ff < tree[2 * index + 1].ff)
    tree[index] = {tree[2 * index].ff, tree[2 * index].ss};
  else if (tree[2 * index].ff > tree[2 * index + 1].ff)
    tree[index] = {tree[2 * index + 1].ff, tree[2 * index + 1].ss};
  else
    tree[index] = {tree[2 * index].ff, tree[2 * index].ss + tree[2 * index + 1].ss};

  return;
}

ll query(ll int ss, ll int se, ll int qs, ll int qe, ll int index)
{
  // complete overlap
  if (ss >= qs and se <= qe)
  {
    return tree[index].ff;
  }
  // No Overlap
  if (qe < ss || qs > se)
    return INT_MAX;

  // partial overlap
  ll int mid = (ss + se) / 2;
  ll l1 = query(ss, mid, qs, qe, 2 * index);
  ll l2 = query(mid + 1, se, qs, qe, 2 * index + 1);
  return min(l1, l2);
}
// point update
void point_update(ll int ss, ll int se, ll int i, ll int inc, ll int index)
{
  if (i > se || i < ss)
    return;
  if (ss == se)
  {
    tree[index] = {inc, 1};
    return;
  }
  ll int mid = (ss + se) / 2;
  point_update(ss, mid, i, inc, 2 * index);
  point_update(mid + 1, se, i, inc, 2 * index + 1);

  if (tree[2 * index].ff < tree[2 * index + 1].ff)
    tree[index] = {tree[2 * index].ff, tree[2 * index].ss};
  else if (tree[2 * index].ff > tree[2 * index + 1].ff)
    tree[index] = {tree[2 * index + 1].ff, tree[2 * index + 1].ss};
  else
    tree[index] = {tree[2 * index].ff, tree[2 * index].ss + tree[2 * index + 1].ss};
  return;
}

ll count_mini(ll int ss, ll int se, ll int qs, ll int qe, ll num, ll int index)
{
  if (ss > qe || se < qs)
    return 0;
  if ((se <= qe || ss >= qs) && tree[index].ff > num)
    return 0;
  if (ss >= qs && se <= qe)
  {
    if (tree[index].ff == num)
      return tree[index].ss; 
    else
      return 0;
  }
  
  ll int mid = (ss + se) / 2;

  ll left = count_mini(ss, mid, qs, qe, num, 2 * index);

  ll right = count_mini(mid + 1, se, qs, qe, num, 2 * index + 1);

  return left + right;

}

void solve()
{
  int n, q;
  cin >> n >> q;

  ll a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  build_tree(a, 0, n - 1, 1);

  // for(int i=1;i<=4*n;i++)
  //   cout<<tree[i].ff<<" "<<tree[i].ss<<endl;
  //   cout<<endl;

  while (q--)
  {
    ll num, l, r;
    cin >> num >> l >> r;
    if (num == 1)
      point_update(0, n - 1, l, r, 1);

    else
    {
      ll int num1 = query(0, n - 1, l, r - 1, 1);
      ll int num2 = count_mini(0, n - 1, l, r - 1, num1, 1);
      cout << num1 << " " << num2 << endl;
    }
  }
}



int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll int t = 1;
  // cin>>t;
  while (t--)
  {
    solve();
  }

  return 0;
}








