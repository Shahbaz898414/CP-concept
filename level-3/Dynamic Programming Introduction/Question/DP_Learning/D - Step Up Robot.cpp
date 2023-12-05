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



// void solve()
// {
//   cin >> n;
//   cout << f(1) << endl;
// }

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;cin>>n;

  vector<int> arr(n+1);

  for (int i =1; i <=n; i++)
  {
    /* code */
    cin>>arr[i];
  }
  

  int m;cin>>m;


  vector<int>  brr(m+1);



  for (int i = 1; i <=m; i++) {

    cin>>brr[i];
    
  }


  int x;cin>>x;

  vector<int> trap(x+1,0);

  for (int i = 1; i <=m; i++)
  {
    /* code */
    trap[brr[i]]=1;
  }

  vector<int>  dp(x+1,0);

  dp[0]=1;

  for (int i = 0; i <=x; i++)
  {
    
    if(!dp[i]) continue;
    for (int j =1; j <=n; j++)
    {
     
      int next=i+arr[j];
      if(next<=x and !trap[next]){
        dp[next]=1;
      }
    }
    
  }


  cout<<(dp[x]==1?"Yes":"No")<<endl;
  

  
}




