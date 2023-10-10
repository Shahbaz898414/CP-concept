#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;

int binary(int A)
{
  int M = mod;
  int m0 = M;
  int y = 0;
  int x = 1;

  if (M == 1)
  {
    return 0;
  }

  while (A > 1)
  {
    int q = A / M;
    int t = M;
    M = A % M;
    A = t;
    t = y;
    y = x - q * y;
    x = t;
  }

  if (x < 0)
  {
    x += m0;
  }

  return x;
}

int main()
{

  ll n, m;
  cin >> n >> m;
  string s;
  cin >> s;

  ll ghg = 1, cnt = 1, b = 0;

  for (ll i = 1; i < s.length(); ++i)
  {
    if (s[i] == '?')
    {
      ghg = (ghg * i) % mod;
    }
  }

  if (s[0] == '?')
  {
    cout << "0" << endl;
  }
  else
  {
    cout << ghg + cnt * b << endl;
  }

  for (ll i = 0; i < m; ++i)
  {
    ll x;
    string y;
    cin >> x >> y;
    --x;

    if (x == 0)
    {
      s = y + s.substr(1);
      if (s[0] == '?')
      {
        cout << "0" << endl;
      }
      else
      {
        cout << max(ghg*cnt,ghg*cnt*b) << endl;
      }
      continue;
         // if (s[x] == '?' && y != "?")
    // {
    //   ghg = ((ghg * binary(x)) % mod) * cnt;
    // }
    // else if (s[x] != '?' && y == "?")
    // {
    //   ghg = ((ghg * x) % mod) * cnt;
    // }
    }

    if (s[x] == '?' && y != "?")
    {
      ghg = ((ghg * binary(x)) % mod) * cnt;
         // if (s[x] == '?' && y != "?")
    // {
    //   ghg = ((ghg * binary(x)) % mod) * cnt;
    // }
    // else if (s[x] != '?' && y == "?")
    // {
    //   ghg = ((ghg * x) % mod) * cnt;
    // }
    }
    else if (s[x] != '?' && y == "?")
    {
      ghg = ((ghg * x) % mod) * cnt;
         // if (s[x] == '?' && y != "?")
    // {
    //   ghg = ((ghg * binary(x)) % mod) * cnt;
    // }
    // else if (s[x] != '?' && y == "?")
    // {
    //   ghg = ((ghg * x) % mod) * cnt;
    // }
    }

    s[x] = y[0];

    if (s[0] == '?')
    {
      cout << "0" << endl;
         // if (s[x] == '?' && y != "?")
    // {
    //   ghg = ((ghg * binary(x)) % mod) * cnt;
    // }
    // else if (s[x] != '?' && y == "?")
    // {
    //   ghg = ((ghg * x) % mod) * cnt;
    // }
    }
    else
    {
      cout << max(ghg + cnt * b, cnt * b) << endl;
         // if (s[x] == '?' && y != "?")
    // {
    //   ghg = ((ghg * binary(x)) % mod) * cnt;
    // }
    // else if (s[x] != '?' && y == "?")
    // {
    //   ghg = ((ghg * x) % mod) * cnt;
    // }
    }
  }

  return 0;
}