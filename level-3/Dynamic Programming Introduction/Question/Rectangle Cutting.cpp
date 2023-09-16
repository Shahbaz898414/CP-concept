#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll nax = 505;
const ll mod = (10e8) + 7;

#define INF 1e9;

int dp[nax][nax];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll t = 1;
  // cin >> t;

  while (t--)
  {

    ll n, m;
    cin >> n >> m;

    for (int i =1; i <=n; i++) {
     
      for (int j=1; j <=m; j++)
      {
       
        dp[i][j]=INF;
      }
      
    }

    for(int i=1;i<nax;i++){
      dp[i][i]=0;
    }

    // for (int i = 0; i < n; i++)
    // {
    //   /* code */
    //   for (int j = 0; j < m; j++)
    //   {
    //     /* code */
    //     cout<<dp[i][j]<<" ";
    //   }

    //   cout<<endl;
      
    // }

    // cout<<endl;

    for(int i=1;i<=n;i++) {
      for(int j=1;j<=m;j++) {

        for(int z=1;z<i;z++) {
          dp[i][j]=min(dp[i][j],dp[z][j]+dp[i-z][j]+1);
        }

        for(int z=1;z<j;z++) {
          dp[i][j]=min(dp[i][j],dp[i][z]+dp[i][j-z]+1);
        }

      }
    }



    // for (int i = 0; i < n; i++)
    // {
    //   /* code */
    //   for (int j = 0; j < m; j++)
    //   {
    //     /* code */
    //     cout<<dp[i][j]<<" ";
    //   }

    //   cout<<endl;
      
    // }
    

    cout<<dp[n][m]<<endl;
    
  }

  return 0;
}