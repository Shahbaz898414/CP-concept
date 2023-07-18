#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ll t;
  cin >> t;
  while (t--)
  {
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);

    vector<ll> b(m);

    vector<ll> ans(n);

    map<int, int> mp1, mp2;

    for (ll i = 0; i < n; i++)
    {

      cin >> a[i];
      mp1[a[i]]++;
    }

    for (ll i = 0; i < m; i++)
    {

      cin >> b[i];
      mp2[b[i]]++;
    }

    for (auto it : mp1)
    {
      if (it.second > 1)
      {
        // if(mp1.find(mp))
      }
    }
  }
  return 0;
}
