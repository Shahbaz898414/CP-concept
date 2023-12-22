#include <bits/stdc++.h>
using namespace std;
#define ll long long



bool dfs(int node, int parent, vector<vector<ll>> &adj, vector<ll> &color, vector<ll> &ones)
{
  bool fl = true;
  for (auto c : adj[node])
  {
    if (c == parent)
      continue;

    if (!dfs(c, node, adj, color, ones))
    {
      fl = false;
    }
  }

  if (fl == true and color[node] == 1)
  {
    ones.push_back(node);
  }

  return color[node] == 1;
}



int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t = 1;

  // cin >> t;

  for (; t--;)
  {
    ll n, q;
    cin >> n >> q;

    // vector<ll>  degree(n+1);

    vector<ll> adj[n + 1];

    for (ll i = 1; i < n; i++)
    {
      /* code */
      ll a, b;
      cin >> a >> b;

      adj[a].push_back(b);
      adj[b].push_back(a);
      // degree[a]++;
      // degree[b]++;
    }



    //  dfs(adj,1,-1,0);
    int timer=0;

    vector<int> pref(n+1,0);


  }
  return 0;
}


/*



*/