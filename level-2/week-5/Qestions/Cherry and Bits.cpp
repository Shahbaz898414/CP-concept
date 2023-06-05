#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ll n, m;
  cin >> n >> m;

  ll arr[n + 1][m + 1];

  for (ll i = 1; i <= n; i++)
  {
    for (ll j = 1; j <= m; j++)
    {
      cin >> arr[i][j];
    }
  }

  vector<vector<int>> ans(n + 1, vector<int>(m + 1, 0));

  ll q;
  cin >> q;
  while (q-- > 0)
  {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ans[x1][y1]++;
    if (x2 + 1 <= n && y2 + 1 <= m)
      ans[x2 + 1][y2 + 1]++;
    if (y2 + 1 <= m)
      ans[x1][y2 + 1]--;
    if (x2 + 1 <= n)
      ans[x2 + 1][y1]--;
  }

  for (int i = 1; i <= n; i++)
  {

    for (int j = 1; j <= m; j++)
    {

      cout << ans[i][j] << " ";
    }

    cout << endl;
  }

  cout << endl;
}
