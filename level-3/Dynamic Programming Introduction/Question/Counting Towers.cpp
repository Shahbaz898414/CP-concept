#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


const ll nax = 1e6 + 10;
const ll mod = (10e8) + 7;


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  vector<vector<ll>> dp(nax,vector<ll>(8,0));

  for (int i = 0; i <8; i++) 
    dp[0][i]=1;
  

  for(int i=1;i<nax;i++){
    for (ll j = 0; j < 8; j++)
    {
      /* code */
      if(j==0 ||j==2 ||j==3 || j==4|| j==5){
        dp[i][j]=(dp[i-1][0]
                              + dp[i-1][1]
                              + dp[i-1][3] +
                                dp[i-1][4] + dp[i-1][5])%mod;
      }else {

          dp[i][j]=(dp[i-1][2]+dp[i-1][6]+dp[i-1][7])%mod;
      }
    }
    
  }
  

  ll t;cin>>t;

  while(t--) {
     ll n,m;cin>>n;

     cout<<((dp[n-1][2]+dp[n-1][6])%mod)<<endl;
  }
  
  

return 0;

}