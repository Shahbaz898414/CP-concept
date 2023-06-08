
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  bool dfs(int node, int parent, int vis[], vector<int> adj[])
  {
    vis[node] = 1;
    for (auto adjacentNode : adj[node])
    {
      if (!vis[adjacentNode])
      {
        if (dfs(adjacentNode, node, vis, adj) == true)
          return true;
      }
      else if (adjacentNode != parent)
        return true;
    }

    return false;
  }

public:
  bool isCycle(int V, vector<int> adj[])
  {
    int vis[V] = {0};

    for (int i = 0; i < V; i++)
    {
      /* code */
      if (!vis[i])
      {
        if (detect(i, adj, vis))
          return true;
      }
    }
  };

  int main()
  {
    int tc;
    cin >> tc;
    while (tc--)
    {
      int V, E;
      cin >> V >> E;
      vector<int> adj[V];
      for (int i = 0; i < E; i++)
      {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
      Solution obj;
      bool ans = obj.isCycle(V, adj);
      if (ans)
        cout << "1\n";
      else
        cout << "0\n";
    }
    return 0;
  }
