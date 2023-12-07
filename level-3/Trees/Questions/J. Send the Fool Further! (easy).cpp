#include <bits/stdc++.h>
using namespace std;
int res, n;
vector<pair<int, int>> e[105];

void dfs(int u, int d, int par)
{
  res = max(res, d);
  for (auto p : e[u])
  {
    if (p.first == par)
      continue;
    dfs(p.first, d + p.second, u);
  }
}

int main()
{
  
  
  int a, b, c;


  cin >> n;


  for (int i = 0; i < n - 1; ++i) {
    cin >> a >> b >> c;
    e[a].push_back({b, c});
    e[b].push_back({a, c});
  }


  dfs(0, 0, -1);


  cout << res << endl;
  return 0;
}