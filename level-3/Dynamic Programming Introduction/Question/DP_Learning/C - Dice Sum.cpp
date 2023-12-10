#include <bits/stdc++.h>
using namespace std;
#define ll long long



#define mod 998244353



ll dp[51][2501];


ll rec(ll i, ll j,ll m)
{
  // memoization
  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  // base
  if(i==0)  return dp[i][j]=1;


  //  transition
  ll ans=0;

  for (int k = 1; k <=m; k++)
  {
    /* code */
    if(j-k>=0){
      ans=(ans+rec(i-1,j-k,m))%mod;
    }
  }
  
  

  return dp[i][j]=ans;
  

}



void solve() {

  
  ll n,m,k;cin >> n>>m>>k;

  for (int i = 0; i <=n; i++)
  {
    /* code */
    for (int j = 0; j <=k; j++)
    {
      /* code */
      dp[i][j]=-1;
    }
    
  }

  cout<<(rec(n,k,m))<<endl;
  

 
  
  
 

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




