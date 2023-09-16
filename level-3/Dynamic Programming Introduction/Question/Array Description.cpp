#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



const ll mod = (10e8) + 7;


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  

  ll n,m;cin>>n>>m;

  vector<int>  val(n);

  for (ll i = 0; i < n; i++)
  {
    /* code */
    cin>>val[i];
  }

  vector<vector<ll>>  num(n,vector<ll>(m+1,0));

  if(val[0]!=0){
    num[0][val[0]]=1;
  }else {
    for (int i =1; i <=m; i++) {
      num[0][i]=1;
    }
    
  }

  for (int i = 1; i < n; i++)
  {
    
    if(val[i]==0){
      for (int j = 1; j <=m; j++)
      {
        
        if(j-1>=1){
          num[i][j]=(num[i][j]+num[i-1][j-1])%mod;
        }

        num[i][j]=(num[i][j]+num[i-1][j])%mod;

        if(j+1<=m)   num[i][j]=(num[i][j]+num[i-1][j+1])%mod;

      }
      
    }else {


      if(val[i]-1>=1){
        num[i][val[i]]=(num[i][val[i]]+num[i-1][val[i]-1])%mod;

      }
      
      num[i][val[i]]=(num[i][val[i]]+num[i-1][val[i]])%mod;

      if(val[i]+1<=m)
        num[i][val[i]]=(num[i][val[i]]+num[i-1][val[i]+1])%mod;


    }
  }

  // for (ll i = 0; i <n; i++)
  // {
  //   /* code */
  //   for (ll j = 0; j <=m; j++)
  //   {
  //     /* code */
  //     cout<<num[i][j]<<" ";
  //   }

  //   cout<<endl;
    
  // }
  

  ll ans=0;

  for (ll i =1; i <=m; i++)
  {
    
    ans=(ans+num[n-1][i])%mod;
  }

  cout<<ans<<endl;
  

  
// 2 0 0 3 0
  



}