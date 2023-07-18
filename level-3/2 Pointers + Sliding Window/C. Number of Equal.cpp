#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
  ll t; cin >> t;
  while (t--) {
    ll n,m; cin >> n>>m; 

    vector<ll>  a(n);

    vector<ll> b(m);

    vector<ll> ans(n);

    map<int,int> mp1,mp2;

    for (ll i = 0; i < n; i++)
    {
      /* code */
      cin>>a[i];
      mp1[a[i]]++;
    }

    for (ll i = 0; i < m; i++)
    {
      /* code */
      cin>>b[i];
      mp2[b[i]]++;
    }
    
    int i=0,j=0,k=0;

    while(i<n){
      while(j<m and b[j]< a[i]){
        j++;
      }

      ans[i]=j;

      i++;
    }

    for(auto it:ans){
      cout<<it<<" ";
    }
  
    cout<<endl;
  }
  return 0;
}

