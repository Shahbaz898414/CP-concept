#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;


int main() {
 
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  ll n, x; cin >> n >> x;

  ll t[n], h[n], m[n];

  for (ll i = 0; i < n; i++) cin >> t[i] >> h[i] >> m[i];


  ll atb = 0;

  for (ll e = 0; e <= 1; e++)
  {
    ll x2 = x;
    vector<bool> ty(n);
    for (ll i = 0; i < n; i++)
    {
      ll c = -1;
      for (ll j = 0; j < n; j++)
      {
        if (!ty[j] && h[j] <= x2 && t[j] == (e + i) % 2)
        {
          if (c == -1 || m[j] > m[c])
          
            c = j;
          
        }
      }
      if (c == -1) break;




      x2 += m[c];

      ty[c] = true;

      atb = max(atb, i + 1);
    }
  }



  cout << atb;



  return 0;
}

