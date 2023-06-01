
#include <bits/stdc++.h>
using namespace std;

class Solution
{

  private:
  void  dfs(int node ,vector<int> adjLs[],int arr[] ){
    arr[node]=1;

    for(auto it:adjLs[node]){
      if(!arr[it]){
        dfs(it,adjLs,arr);
      }
    }

  }

public:
  int numProvinces(vector<vector<int>> adj, int V)
  {

    vector<int>  adjLs[V];

    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) { 
        if(adjLs[i][j]==1 and i!=j){
          adjLs[i].push_back(j);
          adjLs[j].push_back(i);
        }
      }
    }

    int vis[V]={0};
    int cnt=0;
    for (int i = 0; i < V; i++)
    {
      /* code */
      
      if(!vis[i]){
        cnt=0;
        dfs(i,adjLs,vis);
      }
    }

    return cnt;
    
    
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int V, x;
    cin >> V;

    vector<vector<int>> adj;

    for (int i = 0; i < V; i++)
    {
      vector<int> temp;
      for (int j = 0; j < V; j++)
      {
        cin >> x;
        temp.push_back(x);
      }
      adj.push_back(temp);
    }

    Solution ob;
    cout << ob.numProvinces(adj, V) << endl;
  }
  return 0;
}

/*
class Solution {
public:
    vector<int> g[205];
    int n, m, vis[205];

    void dfs(int u) {
        vis[u] = 1;
        for(auto v: g[u]) {
            if(!vis[v]) dfs(v);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        memset(vis, 0, sizeof(vis));
        n = isConnected.size(), m = isConnected[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(isConnected[i][j]) {
                    g[i].push_back(j);
                }
            }
        }

        int ans = 0;
        for(int u=0; u<n; u++) {
            if(!vis[u]) {
                ans++;
                dfs(u);
            }
        }
        return ans;
    }
};

*/
