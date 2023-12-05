#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define mod 998244353


ll dp[200001][2];

ll rec(ll i,bool j,vector<vector<ll>> &a) {
  // memoization
  if(dp[i][j]!=-1){
    return dp[i][j];
  }

  // Base Case
  if(i==0)  return dp[i][j]=1;

  // transition
  ll ans=0;

  if(a[i][j]!=a[i-1][0]){
    ans=(ans+rec(i-1,0,a))%mod;
  }

  if(a[i][j]!=a[i-1][1]){
    ans=(ans+rec(i-1,1,a))%mod;
  }


  return dp[i][j]=ans;
}

void solve() {
   
   ll n;cin>>n;

   vector<vector<ll>> arr(n+1,vector<ll>(2,-1));

   for (ll i = 0; i < n; i++)
   {
    /* code */
    cin>>arr[i][0]>>arr[i][1];
   }

   cout<<rec(n,0,a)<<endl;
   


   


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
int t=1;
// cin>>t;
while(t--)
    solve();

    return 0;
}



/*

1 2
4 2
3 4

1

2 1
4 2
3 4

2

1 2
2 4
3 4

3
1 2
2 4
4 3

4



*/