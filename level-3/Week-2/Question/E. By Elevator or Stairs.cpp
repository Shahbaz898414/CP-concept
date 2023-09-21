#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N=2e5+5;

ll dp[N][2];

int main()
{
  ll t=1;
  // cin >> t;

  while (t--) {
    ll n,c; cin >> n>>c;
    
    vector<ll> arr(n+1),brr(n+1);

    for (ll i = 2; i <=n; i++) {
      cin>>arr[i];
    }

    for (ll i =2; i <=n; i++) {
      cin>>brr[i];
    }

    dp[1][1]=c;

    cout<<0<<" ";

    // cout<<endl;

    vector<int>  vec;
    

    for (ll i = 2; i <=n; i++) { 

      dp[i][0]=min(dp[i-1][0],dp[i-1][1])+arr[i];
      dp[i][1]=min(dp[i-1][0]+c,dp[i-1][1])+brr[i];
      // cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
      cout<<min(dp[i][0],dp[i][1])<<" ";
      // vec.push_back(min(dp[i][0],dp[i][1]));
    }


    // cout<<endl;


    // for(auto it:vec){
    //   cout<<it<<" ";
    // }

    // cout<<endl;
    
    
    
  }
}