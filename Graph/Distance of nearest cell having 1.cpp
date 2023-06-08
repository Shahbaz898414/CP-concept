#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> nearest(vector<vector<int>> grid)
  {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
      /* code */
      for (int j = 0; j < m; j++)
      {
        /* code */
        if (grid[i][j] == 0)
        {
          q.push({{i, j}, 0});
          vis[i][j] = 1;
        }
        else
        {
          v[i][j] = 0;
        }
      }
    }
  }
};

int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> grid[i][j];
      }
    }
    Solution obj;
    vector<vector<int>> ans = obj.nearest(grid);
    for (auto i : ans)
    {
      for (auto j : i)
      {
        cout << j << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
