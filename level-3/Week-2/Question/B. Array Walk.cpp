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
    cin >> n >> k >> z;

    ll ans = 0;

    vector<ll> arr(n + 1);

    for (ll i = 0; i < n; i++)
    {
      /* code */
      cin >> arr[i];
    }

    for (ll i = 0; i <= z; i++)
    {
      /* code */
      ll mx = 0;
      ll val = 0;

      for (ll j = 0; j <= k - 2 * i; j++)
      {
        /* code */
        val += arr[j];
        mx = max(mx, arr[j] + arr[j + 1]);
      }

      ans = max(ans, val + i * mx);
    }


    cout << ans << endl;
  }
}