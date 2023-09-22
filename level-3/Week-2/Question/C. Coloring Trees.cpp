#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 101;
const ll INF = (1e11);
const int mod = 1e9 + 7;

ll dp[N][N][N];
int c[N];

ll cost[N][N];

int main()
{
  ll t = 1;
  // cin >> t;

  while (t--)
  {

    ll n, z;
    ll m, k;
    cin >> n >> m >> k;

    // string s;
    // cin >> s;
    ll ans = 0;

    // vector<ll> arr(n+1);

    for (ll i = 1; i <= n; i++)
    {
      /* code */
      cin >> c[i];
    }

    for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= k; j++)
      {
        for (int a = 0; a <= m; a++)
        {
          dp[i][j][a] = INF;
        }
      }
    }

    for (int i = 1; i <= n; i++)
    {

      for (int j = 0; j <= m; j++)
      {

        cin >> cost[i][j];
      }
    }

    if (c[1] == 0)
    {
      for (int i = 1; i <= m; i++)
      {

        dp[1][1][i] = cost[1][i];
      }
    }
    else
    {
      dp[1][1][c[1]] = 0;
    }

    for (int i = 2; i <= n; i++)
    {

      for (int j = 1; j <= k; j++)
      {
        if (c[i] == 0)
        {
          for (int a = 1; a <= m; a++)
          {
            dp[i][j][a] = min(dp[i][j][a], dp[i - 1][j][a] + cost[i][a]);
            for (int b = 1; b <= m; b++)
            {
              if (b != a)
                dp[i][j][a] = min(dp[i][j][a], dp[i - 1][j - 1][b] + cost[i][a]);
            }
          }
        }
        else
        {
          dp[i][j][c[i]] = min(dp[i][j][c[i]], dp[i - 1][j][c[i]]);
          for (int b = 1; b <= m; b++)
          {
            if (b != c[i])
              dp[i][j][c[i]] = min(dp[i][j][c[i]], dp[i - 1][j - 1][b]);
          }
          // cout << i << ' ' << j << ' ' << c[i] << ' ' << dp[i][j][c[i]] << '\n';
        }
      }
    }
  }
}
