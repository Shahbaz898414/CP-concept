#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long long int

int main()
{

  ll n, k;
  cin >> n >> k;

  vector<ll> arr(n);

  for (ll i = 0; i < n; i++)
  {
    
    cin >> arr[i];
  }

  vector<ll> vec, cnt(k + 1);

  for (ll i = 0; i < n; i++)
  {
    
    if (i == 0 || arr[i] != arr[i - 1])
    {
      vec.push_back(arr[i]);
    }
  }

  for (ll i = 0; i < vec.size(); i++)
  {
    
    if (i > 0 and i < vec.size() - 1 and vec[i - 1] == vec[i + 1])
  
      cnt[vec[i]] += 2;
    
    else
      cnt[vec[i]] += 1;
  }

  int mx = 0, ans = 0;

  for (int i = 1; i <= k; i++)
  {
    
    if (mx < cnt[i])
    {
      ans = i;
      mx = cnt[i];
    }
  }

  cout << ans << endl;

  return 0;
}
