#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define MAXN 202020








int main () {

 


  int n ;cin>>n;

  vector<int> adj[n+1];

  for (int i = 0; i <n-1; i++)
  {
    /* code */
    int u,v;cin>>u>>v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }


  vector<int>  depth(n+1,0);
  vector<int>  diameter(n+1,0);
  vector<int>  ans(n+1,0);
  

  // lamba function

  function<void(int,int)> dfs = [&] (int node,int parent)-> void {
    depth[node]=1;
    diameter[node]=1;

    int mx=0;

    for(int child:adj[node]){
      if(child!=parent){
        dfs(child,parent);

        depth[node]=max(depth[node],depth[child]);
        diameter[node]=max(diameter[node],diameter[child]);
        diameter[node]=max(diameter[node],1+mx+depth[child]);

        mx=max(mx,depth[child]);
      }
    }  

  };

  dfs(1,0);

 
  
  cout<<depth[1]<<endl;
  
  

    
}


/*

2 3 
4 
5



*/