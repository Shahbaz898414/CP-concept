#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ll t;
  cin >> t;

  while (t--)
  {
    ll n;
    cin >> n;

    vector<int> a(n);

    ll l = 0, p = 0, r = 0, ans = 0;

    for (auto &i : a)
      cin >> i;
    
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += a[i];
      if (sum <= 0)
      {
        l = -1;
        break;
      }
    }

   
      
    sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      sum += a[i];
      if (sum <= 0)
      {
        r = -1;
        break;
      }
    }



    if (r == -1 || l == -1 )
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
    
  }
}