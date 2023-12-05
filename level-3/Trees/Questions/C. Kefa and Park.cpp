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

  vector<ll>  adj[n+1],hasCat(n+1);

  for (ll i = 1; i <=n; i++)
  {
    /* code */
    cin>>hasCat[i];
  }
  

  for (ll i = 1; i <n; i++) {
  
    int x,y;cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  function<void(int,int,int)>  dfs=[&](int node,int parent,int cats){
    cats=(hasCat[node]?1+cats:0);
    if(cats>k) return;

    for(auto &i:adj[node]){
      if(i!=parent)  dfs(i,node,cats);
    }

    ans+=(adj[node].size()==1 and adj[node][0]==parent);
  };


  dfs(1,1,0);
  

  cout<<ans<<endl;
  

}

int32_t main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


// #ifndef ONLINE_JUDGE
//   freopen("io/input.txt", "r", stdin);
//   freopen("io/output.txt", "w", stdout);
//   freopen("io/error.txt", "w", stderr);
// #endif


  int t = 1;
  // cin >> t;

  for (int _t = 1; _t <= t; _t++)
  {
    // debug(Testcase, _t);
    solve();
    // crndl;
  }

  return 0;
}




