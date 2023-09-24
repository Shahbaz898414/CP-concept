#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll nax = 505;
const ll mod = (10e8) + 7;

ll modInverse(ll base, ll exp)
{
  if (exp == 0)
  {
    return 1;
  }

  ll res = modInverse(base, exp / 2);
  if (exp % 2 == 1)
  {
    return (((res * res) % mod) * base) % mod;
  }
  else
  {
    return (res * res) % mod;
  }
}

#define INF 1e9;

int dp[nax][nax];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll t = 1;
  // cin >> t;

  while (t--) {
    ll n, k, x;
    cin >> n >> k >> x;
    vector<int> arr(n);

    for (ll i = 0; i < n; i++) {
      cin >> arr[i];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(x + 1, -1e18));

    dp[0][x] = 0;

    for (ll i = 1; i <= n; i++)
    {
      for (ll j = 0; j < x; j++)
      {
        for (ll p = 1; p <= k; p++)
        {
          if (i - p < 0)
            break;
          if (dp[i - p][j + 1] == -1e18)
            continue;

          dp[i][j] = max(dp[i][j], dp[i - p][j + 1] + arr[i - 1]);
        }
      }
    }

    for (ll i = 0; i <=n; i++) {
      for (ll j = 0; j <=x; j++) {
        cout<<dp[i][j]<<" ";
      }
        cout<<endl;
    }

    cout<<endl;
    

    ll ans = -1e18;

    for (ll i = n - k + 1; i <= n; i++) {
      ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
    }

    if (ans == -1e18) {
      ans = -1;
    }



    cout << ans << endl;

  }
  return 0;
}
