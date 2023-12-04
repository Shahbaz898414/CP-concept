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
    if (b & 1)
      temp = (temp * 1LL * a) % mod;
    a = (a * 1LL * a) % mod;

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

  int n, k;
  cin >> n;
  cin >> k;
  
}




/*




*/