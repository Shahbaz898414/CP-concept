#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// vector<ll> dp(4001, -1); // Initialize dp array with -1 values
ll dp[4001];

ll rec(int i, int a, int b, int c)
{
  if (dp[i] != -1)
    return dp[i];

  if (i == 0)
    return dp[i] = 0;

  ll ans = INT_MIN;

  if (i - a >= 0)
    ans = max(ans, 1 + rec(i - a, a, b, c));
  if (i - b >= 0)
    ans = max(ans, 1 + rec(i - b, a, b, c));
  if (i - c >= 0)
    ans = max(ans, 1 + rec(i - c, a, b, c));

  return dp[i] = ans;
}

int main()
{
  int n, a, b, c;
  cin >> n >> a >> b >> c;

  for (int i = 0; i <= n; i++)
  {
    /* code */
    dp[i] = -1;
  }

  cout << rec(n, a, b, c) << endl;

  return 0;
}
