#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  ll n,m;
  cin>>n>>m;

  ll a[n],b[m],sum=0;

  for (int i = 0; i < n; i++) {
    cin>>a[i];
    
  }

  
  for (int i = 1; i <=n; i++) {
    a[i]+=a[i-1];
  }
  
  set<pair<ll,ll>> s;
  s.insert({0,0});

  for (int i = 0; i <n; i++) { 
    s.insert({a[i],i+1});
  }

  for (int i = 0; i <m; i++) {
    ll x;cin>>x;
    
    auto itr=s.lower_bound({x,0});
    cout <<(*itr).second << " ";
    --itr;
    cout<<x - (*itr).first<<"\n";
  }
  
  return 0;
}