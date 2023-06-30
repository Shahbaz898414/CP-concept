#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  ll t;cin>>t;

  while(t--){
    ll n,l,r;cin>>n>>l>>r;
  
    vector<ll>  arr(n);

    for (ll i = 0; i < n; i++) 
      cin>>arr[i];
    

    sort(arr.begin(),arr.end());
    
    
  }

  
  
  return 0;
}