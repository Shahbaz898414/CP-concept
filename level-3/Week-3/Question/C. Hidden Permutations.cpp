#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll query(ll i)
{
  cout << "? " << i + 1 << endl;
  ll x;
  cin >> x;
  return x - 1;
}

int main()
{
  ll t;
  cin >> t;

  while (t--)
  {
    ll n;
    cin >> n;
    ll p[n];
    memset(p, -1, sizeof p);

    for (ll i = 0; i < n; i++)
    {
      if (p[i] == -1)
      {
        ll cur = query(i);
        while (p[cur] == -1)
        {
          ll temp = cur;
          cur = query(i);
          p[temp] = cur;
        }
      }
    }

    cout << "! ";
    for (ll i = 0; i < n; i++)
      cout << p[i] + 1 << " ";
    cout << endl;
  }
  return 0;
}

/*





*/
