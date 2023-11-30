#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a, b) for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mod 1000000007
#define MOD 998244353
#define inf (1LL << 60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll, pair<ll, ll>>
#define fast_io                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)
using namespace std;

ll dp2[101][101];
ll dp1[101][101];

ll bin_exp(ll a, ll x, ll mdd)
{
  if (x == 0)
    return 1;

  ll ans = bin_exp(a, x / 2, mdd);
  ans = (ans * ans) % mdd;
  return (x % 2) ? (ans * a) % mdd : ans;
}

ll mulinv(ll a, ll mdd = MOD)
{
  return bin_exp(a, mdd - 2, mdd);
}

int main()
{

  fast_io;

  ll t = 1;
  // cin >> t;

  while (t--)
  {

    ll n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;

    for (ll i = 0; i < n; i++)
    {

      for (ll j = 0; j < n; j++)
      {

        dp2[i][j] = dp1[i][j] = 0;
      }
    }

    for (ll j = 0; j < n; j++)
    {

      dp2[0][j] = dp1[0][j] = (j == 0);
    }

    for (ll i = 0; i < n; i++)
    {

      for (ll j = 0; j < n - a; j++)
      {
        for (ll k = 1; k <= p; k++)
        {
          dp1[i + 1][min(n - a, j + k)] = (dp1[i + 1][min(n - a, j + k)] + (dp1[i][j] * mulinv(p)) % MOD) % MOD;
        }
      }
    }

    for (ll i = 0; i < n; i++)
    {

      for (ll j = 0; j < n - b; j++)
      {
        for (ll k = 1; k <= q; k++)
        {

          dp2[i + 1][min(n - b, j + k)] = (dp2[i + 1][min(n - b, j + k)] + (dp2[i][j] * mulinv(q)) % MOD) % MOD;
        }
      }
    }

    ll ans = 0;

    for (ll i = 1; i <= n; i++)
    {

      ll x = dp1[i][n - a];

      ll y = 0;

      for (ll j = 0; j < n - b; j++)
      {

        y = (y + dp2[i - 1][j]) % MOD;
      }

      ans = (ans + (x * y) % MOD) % MOD;
    }

    cout << ans << endl;
  }

  return 0;
}
