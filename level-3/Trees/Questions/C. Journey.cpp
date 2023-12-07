#include <bits/stdc++.h>
using namespace std;

int main()
{

  int n;
  cin >> n;
  vector<int> adj[n + 1];
  for (int i = 1; i < n; i++)
  {
    /* code */
    int a, b;
    cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  long double ans = 0;

  function<void(int, int, int, double)> dfs = [&](int node, int parent, int path, double pro)
  {
    for (auto &i : adj[node])
    {

      if(i!=parent)
         dfs(i, node, path + 1, pro / (adj[node].size() - (parent != -1)));
    }

    if (adj[node].size() == 1 and adj[node].front() == parent)
    {
      ans += pro * path;
    }
  };

  dfs(1, -1, 0, 1);

  cout << setprecision(25) << ans << endl;

  return 0;
}


