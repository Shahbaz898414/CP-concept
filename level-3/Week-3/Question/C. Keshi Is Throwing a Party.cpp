#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod= 1000000009;
const int mx = 1e6;
ll a[mx];
ll b[mx];
ll n;

bool check(int k) {
  int r = k - 1, p = 0;

  for (int i = 1; i <= n; i++)
    if (a[i] >= r && b[i] >= p)
      r--, p++;

  return p >= k;
}




int main() {

  ll t; cin >> t;
  while (t--) {
    cin >> n;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    /* code */
    int l = 1;
    int r = n;
    int mid;

    while (l <= r)
    {
      mid = (l + r) / 2;
      // cout<<mid<<"m ";
      if (check(mid))
        l = mid + 1;
      else
        r = mid - 1;
    }
    cout<<endl;
    cout << l - 1 << endl;
  }

  return 0;
}
