#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = (10e8) + 7;

// ll   f[2][100001],a[2][100001];

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  ll len = s.size();

  for (char i : s)
  {
    if (i == 'w' || i == 'm')
    {
      cout << 0 << endl;
      return 0;
    }
  }

  int n = s.size();
  vector<int> dp(n + 1);
  dp[0] = dp[1] = 1;
  for (int i = 2; i <= n; i++)
  {
    dp[i] = dp[i - 1];
    if (s[i - 1] == s[i - 2] && (s[i - 1] == 'u' || s[i - 1] == 'n'))
    {
      dp[i] = (dp[i] + dp[i - 2]) % mod;
    }
  }
  
  cout << dp[n] << endl;


}

// ouuokarinn
/*

ouuokarinn
owokarim


*/