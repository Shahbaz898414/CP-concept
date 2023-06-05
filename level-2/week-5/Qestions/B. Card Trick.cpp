#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    ll n;
    cin >> n;
    ll arr[n];

    for (ll i = 0; i < n; i++)
    {
      
      cin >> arr[i];
    }

    ll m,p=0;cin>>m;

    

    for (int i = 0; i < m; i++) {
      ll x;cin>>x;

      p=(p+x)%n;
    }

    cout<<arr[p]<<endl;
    
  }
}
