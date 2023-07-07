#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e6+10;

int a[N],b[N];
int n;

bool check(ll x) {
  ll sum=0;
  for (int i = 1; i <=n; i++) {
    if(a[i]>x) {
      sum+=b[i];
    }
  }

  return sum<=x;
}



int32_t main() {
 
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {

    cin>>n;

    // vector<ll> arr(n+1),brr(n+1);

    for (ll i = 1; i <=n; i++)
    {
      /* code */
      cin>>a[i];
    }
    

    for (ll i = 1; i <=n; i++)
    {
      /* code */
      cin>>b[i];
    }

    ll l=1,r=1e9;

    while (l<r)
    {
      /* code */
      ll mid=(l+r)>>1;

      if(check(mid)) {
        r=mid;
      }else {
        l=mid+1;
      }
    }
    
    cout<<l<<endl;
  
  }
  return 0;
}


