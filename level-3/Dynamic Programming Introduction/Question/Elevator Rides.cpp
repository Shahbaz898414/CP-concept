#include <iostream>
#include <vector>
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

  while (t--)
  {

    ll n, m;
    cin >> n >> m;

    ll sum;

    vector<ll> sub, che, ar(n + 1);

    for (ll i = 0; i < n; i++)
    {
      /* code */
      cin >> ar[i];
    }

    ll limit = (1 << n);

    vector<pair<ll, ll>> dp(limit);

    dp[0] = {1, 0};

    for (ll i = 1; i < limit; i++)
    {
      /* code */

      pair<ll, ll> result = {INT_MAX, INT_MAX};
    }
  }
  return 0;
}
