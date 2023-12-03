#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = (10e8) + 7;

// ll   f[2][100001],a[2][100001];

int dp[51][10001];

int rec(int i,int x,vector<vector<int>>&a){
  if(i==a.size()){
    if(x==0)   return 1;
    else return 0;
  }

  if(x==0){
    return 1;
  }

  if(dp[i][x]!=-1){
    return dp[i][x];
  }

  int take=rec(i+1,x,a);
  for (int j = 1; j <=a[i][1]; j++)
  {
    /* code */
    if(x>=(a[i][0]*j)){
      take|=rec(i+1,x-(a[i][0]*j),a);
    }
  }
  


  return dp[i][x]=take;
}



int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp,-1,sizeof(dp));


  int n,x;cin>>n>>x;

  vector<vector<int>> a(n,vector<int>(2,0));

  for (int i = 0; i < n; i++)
  {
    /* code */
    cin>>a[i][0]>>a[i][1];
  }
  

  int ans=rec(0,x,a);

  cout<<(ans==0?"NO":"YES")<<endl;



}

