#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{

  ll n, t;
  cin >> n;
  vector<ll> arr(n);

  for (ll i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  ll k;
  cin >> k;

  ll l = 0, r = n - 1;

  //  1  3  4  10  10

  for (ll i = 0; i < k; i++)
  {
    ll x, y;
    cin >> x >> y;

    auto itl = lower_bound(arr.begin(), arr.end(), x);
    auto itr = upper_bound(arr.begin(), arr.end(), y);

    cout << itl << " " << itr << endl;

    cout << itr - itl << " ";
  }

  cout << endl;

  //  while(k--) {

  //  }

  return 0;
}
