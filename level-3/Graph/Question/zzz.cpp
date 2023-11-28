#include <bits/stdc++.h>
using namespace std;
long long n, x, y, z;
vector<int> g[1000100];
void dfs(int v, int f)
{
  z = 1 - z;
  z ? x++ : y++;
  for (auto it : g[v])
  {
    if (it != f)
      dfs(it, v);
  }
  z = 1 - z;
}
int main()
{
  cin >> n;
  for (int i = 1; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1, 0);
  cout << ((x * y) - n + 1);
}