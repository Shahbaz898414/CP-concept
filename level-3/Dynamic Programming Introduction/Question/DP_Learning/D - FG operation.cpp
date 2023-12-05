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

// void solve()
// {
//   cin >> n;
//   cout << f(1) << endl;
// }

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;cin >> n;


  vector<int> arr(n + 1);


  for (int i = 1; i <= n; i++) {

    cin >> arr[i];

  }


  vector<vector<ll>> dp(n + 1, vector<ll>(10, 0));


  dp[1][arr[1]] = 1;


  for (int i = 1; i <= n - 1; i++) {


    for (int j = 0; j < 10; j++) {


      dp[i + 1][(j + arr[i + 1]) % 10] += dp[i][j];


      dp[i + 1][(j * arr[i + 1]) % 10] += dp[i][j];


      dp[i + 1][(j + arr[i + 1]) % 10] %= mod;


      dp[i + 1][(j * arr[i + 1]) % 10] %= mod;


    }


  }



  for (int k = 0; k < 10; k++)
    cout << dp[n][k] << endl;
  
}
