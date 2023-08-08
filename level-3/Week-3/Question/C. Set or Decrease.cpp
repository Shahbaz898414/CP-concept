#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{

  ll t;
  cin >> t;

  while (t--)
  {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    ll sum = 0;

    for (ll i = 0; i < n; i++)
    {
      cin >> arr[i];
      sum += arr[i];
    }
  }

  return 0;
}
