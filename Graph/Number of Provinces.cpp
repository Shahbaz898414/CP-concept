
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numProvinces(vector<vector<int>> adj, int V)
  {
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
