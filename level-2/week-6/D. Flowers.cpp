#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

int tc,k;

int dp[100013];

int solve(int n){



  if(n==0) return 1;
  if(n<0)  return 0;
  // if(n<k) return 1;

  if(dp[n]!=-1)  return dp[n];

  return dp[n]=(solve(n-k)+solve(n-1))%mod;
}


signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(dp,-1,sizeof dp);

  cin>>tc>>k;

  int pre[100013];
  pre[0]=solve(0);
  for (int i = 1; i < 100013; i++)
  {
    /* code */
    pre[i]=(pre[i-1]+solve(i))%mod;
  }
  


  while(tc--){
    int a,b;cin>>a>>b;

    // int sum=0;
    cout<<((pre[b]-pre[a-1])%mod+mod)%mod<<endl;
    // for (int i = a; i <=b; i++) {
    //   sum=(solve(i)+sum)%mod;
    // }

    // cout<<sum<<endl;
    
  }
  
}
