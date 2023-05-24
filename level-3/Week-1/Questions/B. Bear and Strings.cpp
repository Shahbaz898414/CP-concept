#include <bits/stdc++.h>
#define ll long long
const int mod = 1e9 + 7;
using namespace std;

ll backbox(string &s)
{
  ll ans = 0;
  ll pr = 1;
  for (ll i = 0; i < s.size(); i++)
  {
    ans = (ans + ((s[i] - 'a' + 1LL) * pr) % mod) % mod;
    pr = (pr * 31LL) % mod;
  }
  return ans;
}

ll power(ll base, ll x)
{
  ll ans = 1;
  while (x)
  {
    if (x % 2 == 0)
    {
      base = (base * base) % mod;
    }
    else
    {
      ans = (ans * base) % mod;
      x--;
    }
  }

  return ans;
}

int32_t main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  ll k=0,d=0;
  ll len = s.size();

  for (ll i = 0; i < len; i++)
  {
    string r = s.substr(i, 4);
   if (r == "bear")
      k += (len - i - 3) * (i + 1) - d * (len - i - 3), d = i + 1;
    
  }


  cout << k<<endl;

  return 0;
}
