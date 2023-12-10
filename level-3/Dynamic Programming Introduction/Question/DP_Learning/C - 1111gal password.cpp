#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define mod 998244353



ll dp[1000001][10];



ll rec(ll i, ll j)
{
  // memoization
  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  // base
  if(i==0)  return dp[i][j]=1;


  //  transition
  ll ans=0;

  for (int k = max(j-1,1LL); k <=min(9LL,j+1); k++) {
    
    ans=(ans+rec(i-1,k))%mod;
  }


  return dp[i][j]=ans;
  

}



void solve() {

  
  ll n;cin >> n;

  for (ll i = 0; i <=n; i++)
  {
    
    for (ll j = 0; j <10; j++)
    {
      
      dp[i][j]=-1;
    }
    
  }


  ll ans=0;

  for (int i = 1; i <10; i++)
  {
    
    ans=(ans+rec(n-1,i))%mod;
  }

  cout<<ans<<endl;
  
  
 

}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;

  while (t--)
    solve();

  return 0;
}




