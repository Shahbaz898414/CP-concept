#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<ll> v(250001, 0);
  vector<ll> bt(250001, 0);

  for (int i = 0; i < n; i++) {
    ll x, y; cin >> x >> y;
    v[x]++;
    v[y + 1]--;
  }

  // for (int i = 0; i < n + 1; i++)
  // {

  //   cout << v[i] << " ";
  // }

  // cout << endl;

  ll sum = 0;

  for (int i = 0; i < 200001; i++)
  {
    /* code */
    sum += v[i];
    bt[i] = sum;
    if(bt[i]>=k){
      bt[i]=1;

    }else {
      bt[i]=0;
    }
  }

  for (int i = 0; i < 200001; i++) {
    /* code */
    bt[i]+=bt[i-1];
  }
  


  while(q--) {
    ll x,y;cin>>x>>y;

    ll ans=bt[y];

    if(x-1>=0){
      ans-=bt[x-1];
    }

    cout<<ans<<endl;
  }
}
