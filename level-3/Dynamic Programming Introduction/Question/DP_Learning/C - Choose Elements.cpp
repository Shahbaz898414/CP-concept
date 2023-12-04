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
  vector<int> a(n), b(n);

  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  vector<vector<bool>> dp(2, vector<bool>(n, 0));

  dp[0][0] = 1;
  dp[1][0] = 1; // BASE CASE

  for (int i = 1; i < n; i++)
  {
    // check for dp[0][i] , that is X[i] = a[i]
    if (dp[0][i - 1] && abs(a[i - 1] - a[i]) <= k)
      dp[0][i] = 1;
    if (dp[1][i - 1] && abs(b[i - 1] - a[i]) <= k)
      dp[0][i] = 1;

    // check for dp[1][i] , that is X[i] = b[i]
    if (dp[0][i - 1] && abs(a[i - 1] - b[i]) <= k)
      dp[1][i] = 1;
    if (dp[1][i - 1] && abs(b[i - 1] - b[i]) <= k)
     
      dp[1][i] = 1;
  }

  
  if (dp[0][n - 1] || dp[1][n - 1])
    cout << "Yes";
  else
    cout << "No";
}

/*


Problem Statement
You are given two sequences, each of length  N, consisting of integers:  A=(A  1 ​  ,…,A  N ​  ) and  B=(B  1 ​  ,…,B  N ​  ).  Determine whether there is a sequence of length  N,  X=(X  1 ​  ,…,X  N ​  ), satisfying all of the conditions below.  X  i ​  =A  i ​   or  X  i ​  =B  i ​  , for every  i(1≤i≤N).  ∣X  i ​  −X  i+1 ​  ∣≤K, for every  i(1≤i≤N−1).

*/