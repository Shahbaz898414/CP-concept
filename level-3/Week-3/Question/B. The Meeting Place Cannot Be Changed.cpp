#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1000000009;
const int mx = 1e6;
ll a[mx];
ll b[mx];

bool isPossible(ll *p, ll *v, ll n, double t)
{
  double left = -1e9, right = 1e9;
  for (ll i = 0; i < n; i++)
  {
    left = max(left, p[i] - v[i] * t);
    right = min(right, p[i] + v[i] * t);
  }
  if (left <= right)
    return true;
  return false;
}

int main()
{

  ll n;
  cin >> n;
  ll p[n];
  ll v[n];

  for (ll i = 0; i < n; i++)
    cin >> p[i];
  for (ll i = 0; i < n; i++)
    cin >> v[i];

  double l = 0.0, r = 1e9, mid;
  while (r - l > 1e-6)
  {
    mid = l + (r - l) / 2;

    // cout<<mid<<" ";
    if (isPossible(p, v, n, mid))
    {
      r = mid;
    }
    else
    {
      l = mid;
    }
  }
  cout << endl;
  cout << endl;

  // if(l==r)  cout<<"YES"<<endl;
  // else cout<<"NO"<<endl;

  // printf("%.9lf ",r);
  cout << fixed;
  cout << setprecision(12);
  cout << r;
  return 0;

  return 0;
}
