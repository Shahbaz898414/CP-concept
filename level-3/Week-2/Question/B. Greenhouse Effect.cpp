#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;

ll dp[N][2];

int main()
{
  ll t = 1;
  // cin >> t;

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
      ll mx=0;
      for (ll j = 0; j < n; j++)
      {
        /* code */

        if(vis[j]<=vis[i]) mx=max(mx,dp[j]);
      }

      dp[i]=mx+1;

      // for(auto it:dp){
      //   cout<<it<<" ";
      // }

      // cout<<endl;
      
    }



    // for(auto it:dp) {
    //   cout<<it<<" ";
    // }



    // cout<<endl;

    cout<<n-*max_element(dp.begin(),dp.end())<<endl;


    
    

    

  }
}



/*



9 4
1 14.284235
1 17.921382
4 20.328172
2 20.328172
3 20.842331
1 25.790145
2 27.204125
4 25.790145
3 27.204125



1 0 0 0 0 0 0 0 0 0 ->1

1 2 0 0 0 0 0 0 0 0  ->1

1 2 3 0 0 0 0 0 0 0   -> 4

1 2 3 3 0 0 0 0 0 0   ->2

1 2 3 3 4 0 0 0 0 0   ->3

1 2 3 3 4 3 0 0 0 0   ->1

1 2 3 3 4 3 4 0 0 0   ->2

1 2 3 3 4 3 4 5 0 0   ->4 

1 2 3 3 4 3 4 5 5 0    ->3




*/