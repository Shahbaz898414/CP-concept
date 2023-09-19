
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

    int n;
    ll maxWeight;
    cin >> n >> maxWeight;
    vector<ll> people(n);
    for (int i = 0; i < n; i++)
      cin >> people[i];

    int limit = (1 << n);
    vector<pair<ll, ll>> dp(limit);
    dp[0] = {1, 0};

    for (int mask = 1; mask < limit; mask++)
    {
      pair<ll, ll> bestResult = {INT_MAX, INT_MAX};

      for (int i = 0; i < n; i++)
      {
        if (((1 << i) & mask) == 0)
          continue;

        auto res = dp[(1 << i) ^ mask];

        if (res.second + people[i] <= maxWeight)
        {
          res.second += people[i];
        }
        else
        {
          res.first += 1;
          res.second = people[i];
        }

        bestResult = min(bestResult, res);
      }

      dp[mask] = bestResult;
    }

    // for(auto it:dp){
    //   cout<<it.first<<" "<<it.second<<endl;
    // }

    cout << dp[limit - 1].first;
  }
  return 0;
}



