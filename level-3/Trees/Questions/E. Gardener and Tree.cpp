#include <bits/stdc++.h>
using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
// #include "algo/debug.h"
#else
#define dbg(...) ;
#define debug(...) ;
#define crndl ;
#endif

void solve() {


  ll n,k;cin>>n>>k;
  ll ans=0;

 vector<set<ll>>  graph(n);

  int connect[n]={0};


  for (int i = 0; i <n-1; i++)
  {
    /* code */

    int v,u;cin>>u>>v;

    u--;v--;

    graph[u].insert(v);
    graph[v].insert(u);
    connect[v]++;
    connect[u]++;

  }

  set<pair<int,int>> s;

  for (int i = 0; i < n; i++)
  {
    /* code */
  }
  
  

  // return 0;
}




