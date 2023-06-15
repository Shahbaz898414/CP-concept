#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 1;

int n;

int a[23];

int sum = 0;

int solve(int i = 0, int s = 0)
{
  if (i == n)
  {
    int other = sum - s;

    return abs(s - other);
  }

  return min(
    solve(i + 1, a[i] + s),
    solve(i + 1, s)
    );

    
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  cout << solve() << endl;
}
