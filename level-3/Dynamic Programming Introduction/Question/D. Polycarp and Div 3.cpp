#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = (10e8) + 7;

// ll   f[2][100001],a[2][100001];

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n;cin >> n;


  ll a[n], b[n];


  for (ll i = 0; i < n; i++) cin >> a[i];


  for (ll i = 0; i < n; i++) cin >> b[i];


  for (ll i = 1; i < n; i++ )  {


    a[i] = max(a[i - 1], a[i] + b[i - 1]);


    b[i] = max(b[i - 1], b[i] + a[i - 1]);


  }

  // for (ll i = 0; i < n; i++)
  // {
  //   /* code */
  //   cout<<a[i]<<" "<<b[i]<<endl;
  // }

  // cout<<endl;
  


  cout << max(a[n - 1], b[n - 1]);


}
