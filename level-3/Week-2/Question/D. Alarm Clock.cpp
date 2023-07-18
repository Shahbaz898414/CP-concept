#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long long int

int main()
{

  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> arr(n);

  for (ll i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  queue<int> q;

  int ans = 0;

  sort(arr.begin(), arr.end());

  for (ll i = 0; i < n; i++)
  {
    /* code */
    cout<<arr[i]<<" ";
  }

  cout<<endl;
  
  vector<ll> brr;
  for (ll i = 0; i < n; i++)
  {

    while (q.size() and arr[i] - q.front() >= m)
    {

      brr.push_back(arr[i]);
      q.pop();

    }

    if (q.size() >= k - 1)
    {
      ans++;
    }
    else
    {
      q.push(arr[i]);
    }
  }

  cout << ans << endl;

  return 0;
}
