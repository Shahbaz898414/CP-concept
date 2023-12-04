#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 998244353;

ll binExp(ll a, ll b)
{
  ll temp = 1;

  while (b > 0)
  {
    if (b & 1) temp = (temp *1LL* a) % mod;
    a = (a *1LL* a) % mod;

    b >>= 1;
  }

  return temp % mod;


}

ll inv(ll n)
{
  return binExp(n, mod - 2) % mod;
}



ll n;


map<ll, ll> dp;



ll f(ll i)
{
  if (i == n)
    return 1;
  if (i > n)
    return 0;

  if (dp.find(i) != dp.end())
  {
    return dp[i];
  }

  ll ans = 0;

  for (ll x = 2; x <= 6; x++)
  {
    /* code */
    ans = (ans + f(x * i) * inv(5)) % mod;
  }


  dp[i] = ans;


  return dp[i] % mod;


}

// void solve()
// {
//   cin >> n;
//   cout << f(1) << endl;
// }

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x; cin >> n >> x;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

  // base case
    dp[1][a[1]] = 1;
    dp[1][b[1]] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (dp[i - 1][j] == 1)
            {
                if (j + a[i] <= x) dp[i][j + a[i]] = 1;
                if (j + b[i] <= x) dp[i][j + b[i]] = 1;
            }
        }
    }

    

    // final answer
    if (dp[n][x] == 1) cout << "Yes" << endl;
    else cout << "No" << endl;


}

/*


Problem Statement
Takahashi is standing at the coordinate  0 on a number line.  He will now perform  N jumps. In the  i-th jump  (1≤i≤N), he moves  a  i ​   or  b  i ​   in the positive direction.  Is it possible for him to be at the coordinate  X after  N jumps?

*/