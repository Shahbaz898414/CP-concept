#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 998244353;

ll binExp(ll a, ll b)
{
  ll temp = 1;

  while (b > 0)
  {
    if (b & 1)
      temp = (temp * 1LL * a) % mod;
    a = (a * 1LL * a) % mod;

    b >>= 1;
  }

  return temp % mod;
}

ll inv(ll n)
{
  return binExp(n, mod - 2) % mod;
}

ll n;

map<ll, ll> dp;

ll f(ll i)
{
  if (i == n)
    return 1;
  if (i > n)
    return 0;

  if (dp.find(i) != dp.end())
  {
    return dp[i];
  }

  ll ans = 0;

  for (ll x = 2; x <= 6; x++)
  {
    /* code */
    ans = (ans + f(x * i) * inv(5)) % mod;
  }

  dp[i] = ans;

  return dp[i] % mod;
}

// void solve()
// {
//   cin >> n;
//   cout << f(1) << endl;
// }

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n;
  cin >> k;

  vector<vector<char>> grid(n,vector<char>(k,0));


  for (ll i = 0; i < n; i++) {
    

    for (ll j = 0; j < k; j++){
      

      cin>>grid[i][j];


      // cout<<grid[i][j];


    }

    // cout<<endl;

  }

  if(grid[0][0]=='#') {
    cout<<0;

    return 0;
  }

  vector<vector<ll>> dp(n,vector<ll>(k,-1));

  dp[0][0]=1;

  ll res=1;

  for (int i = 1; i < k; i++)
  {
    /* code */
    if(grid[0][i]=='#') break;
    dp[0][i]=dp[0][i-1]+1;

    res=max(res,dp[0][i]);
  }
  

  for (ll i = 1; i < n; i++)
  {
    /* code */
    if(grid[i][0]=='#'){
      break;
    }

    dp[i][0]=dp[i-1][0]+1;
    res=max(res,dp[i][0]);
  }



  for (ll i = 1; i < n; i++)
  {
    
    for (ll j = 1; j <k; j++)
    {
      
      if(grid[i][j]=='.') {


        if(grid[i-1][j]=='.' and dp[i-1][j]!=-1){
          dp[i][j]=dp[i-1][j]+1;
        }


        if(grid[i][j-1]=='.' and dp[i][j-1]!=-1){
          dp[i][j] = dp[i][j-1]+1;
        }


        res=max(res,dp[i][j]);


      }
    }
    
  }
  


cout<<res<<endl;
  
  


  
}




