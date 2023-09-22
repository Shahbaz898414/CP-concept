#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;

ll dp[N][2];

int main()
{
  ll t = 1;
  cin >> t;

  while (t--)
  {

    ll n,  z; double m;
    cin >> n>>m;



    // string s;
    // cin >> s;
    ll ans = 0;

    vector<ll> vis(n);

    double x;

    for (ll i = 0; i < n; i++)
    {
      /* code */
      cin>>vis[i]>> x;
    }


    vector<ll>  dp(n+1);

    for (ll i = 0; i < n; i++)
    {
      /* code */
      int mx=0;
      for (ll j = 0; j < n; j++)
      {
        /* code */

        if(vis[j]<=vis[i]) mx=max(mx,dp[j]);
      }
      
    }
    
    

    

  }
}



