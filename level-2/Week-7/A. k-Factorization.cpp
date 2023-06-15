#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 1;



signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,k;cin>>n>>k;

  vector<ll> v;

  ll ans=n;

  for (ll i =2; i <=n; i++) {
    while(n%i==0){
      v.push_back(i);
      n/=i;
    }
  }
  
  if(v.size()>=k){
    for (int i = 0; i < k-1; i++)
    {
      /* code */
      cout<<v[i]<<" ";
      ans=ans/v[i];
    }

    cout<<ans<<endl;
    
  }else{
    cout<<"-1"<<endl;
  }





  
}
