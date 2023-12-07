#include <bits/stdc++.h>
using namespace std;





int main() {

  int n;cin>>n;

  vector<int>  adj[n+1];


  vector<int>  degree(n+1);
  vector<int> subtree(n+1,1);

  for (int i = 1; i <n; i++)
  {
    /* code */
    int x,y;cin>>x>>y;

    adj[x].push_back(y);
    adj[y].push_back(x);
    degree[x]++;
    degree[y]++;
  }

  
    
  
  return 0;
}