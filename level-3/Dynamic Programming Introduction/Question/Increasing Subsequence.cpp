#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll nax = 505;
const ll mod = (10e8) + 7;






ll modInverse(ll base, ll exp)
{
  if (exp == 0)
  {
    return 1;
  }

  ll res = modInverse(base, exp / 2);
  if (exp % 2 == 1)
  {
    return (((res * res) % mod) * base) % mod;
  }
  else
  {
    return (res * res) % mod;
  }
}

#define INF 1e9;

int dp[nax][nax];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll t = 1;
  // cin >> t;

  while (t--)
  {

    ll n, m; cin >> n;

   

    ll sum;

    vector<ll> sub;

    for (ll i = 0; i < n; i++)
    {
      /* code */

      ll x;cin>>x;

      ll idx=lower_bound(sub.begin(),sub.end(),x)-sub.begin();

      if(idx==sub.size()){
        sub.push_back(x);
      }else {
        sub[idx]=x;
      }
    }


    cout<<sub.size()<<endl;

  }
  return 0;
}









