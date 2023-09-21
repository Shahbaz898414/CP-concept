#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;

ll dp[N][2];

int main()
{
  ll t = 1;
  cin >> t;

  while (t--)
  {

    ll n, k, z;
    cin >> n;

    string s;
    cin >> s;
    ll ans = 0;

    vector<ll> vis(n);

    for (ll i = 0; i < n;)
    {
      /* code */

      if (vis[i])
        break;

      int j = 0, k, cnt = 0;

      j = i;
      while (s[j] == s[i] and j < n)
      {
        vis[j++] = 1, cnt = 1;
      }

      if (i == 0)
      {
        k = n - 1;

        while (k > i and !vis[k] and s[k] == s[i])
        {
          vis[k--] = 1;
          cnt++;
        }
      }

      ans += (cnt + 2 * (cnt == n) / 3);

      i = j;
    }

    cout << ans << endl;
  }
}