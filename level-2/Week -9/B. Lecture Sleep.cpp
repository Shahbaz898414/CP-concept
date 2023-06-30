#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m;
  cin >> n >> m;

  ll a[n], b[n], total = 0, ans;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
    if (b[i])
      total += a[i];
  }

  ll sum = 0;

  for (int i = 0; i < m; i++)
  {
    if (!b[i])
      sum += a[i];
  }
  ans = sum;

  for (int i = m; i < n; i++)
  {
    
    if (!b[i])
      sum += a[i];
    if (!b[i - m])
      sum -= a[i - m];
    ans = max(ans, sum);
  }

  cout << ans + total << endl;

  return 0;
}