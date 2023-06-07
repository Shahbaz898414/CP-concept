#include<bits/stdc++.h>
#define ll long long
using namespace std;

const mod=1000;
int main( ) {
  int n, m,c;cin >> n >> m>>c;
  ll arr[n],b[m];

  vector<ll> t(n,0);

  for (int i = 0; i < n; i++) {
    cin>>arr[i];
  }

  for (ll i = 0; i < m; i++) {
    cin>>b[i];

    ll l=1;
    ll r=n-m+i;
    t[l]+=b[i];
    if(r+1<n){
      t[r+1]-=b[i];
    }
  }

  ll sum=0;

  for (int i = 0; i < n; i++)
  {
    /* code */
    sum+=b[i];
    t[i]=sum;
    ll ans=((sum%mod)+(a[i]%mod))%mod;

    cout<<ans<<" ";

  }

  cout<<endl;
  
  
}

