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
    cin >> n;

    // cout<<n*n<<endl;

    ll sum;

    sum = (n * (n + 1)) / 2;
    if (sum % 2)
    {
      cout << 0 << endl;
      return 0;
    }

    sum = sum / 2;

    vector<ll> cnt(sum + 1);

    cnt[0] = 1;

    for (int i = 1; i <= n; i++) {

      for (int j = sum; j >= i; j--) {
        cnt[j] = (cnt[j] + cnt[j - i]) % mod;
      }
    }

    // cout<<cnt[sum]<<endl;

    cout << (cnt[sum] * modInverse(2, mod - 2)) % mod << endl;
  }

  return 0;
}

// sha