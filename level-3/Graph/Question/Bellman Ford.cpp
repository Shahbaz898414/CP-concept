/*


Given a graph of N (N<=10^5) node and M edges  (M<=10^5)  and 2 nodes A and B. Find out all the nodes  which lie any one of the shortest path  from A to B.


*/



#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 202020


#define ff first
#define ss second


#define INF  INT_MAX

// Question -> You have been given a graph
// You have to find the shortest distance for every node from some source node
// You should be able to find the shortest path

vector<int>  bellmanFord(int n,int src,vector<vector<int>>  &edges) {

  vector<int>  dist(n,1e9);


  vector<int>  from(n,1e9);


  dist[src]=0;

  int x;

  for (int i = 0; i < n-1; i++) {


    x=-1;


    for(auto edge:edges) {


      int u=edge[0],v=edge[1],wt=edge[2];


      if(dist[u]!=1e9){


        dist[u]=min(dist[v],dist[u]+wt);


        from[v]=u;


        x=v; 


      }


    }


  }

  int node=n-1;

  vector<int> path={node};

  while(node!=src) {
    node=from[node];
    path.push_back(node);
  }

  reverse(path.begin(),path.end());



  if(x != -1){
    return {};
  }



  return dist;
  
}








int main() {
    int n;
    cin >> n;

    vector<int> adj[n + 1];

    for (int i = 0; i <n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> sizes(n + 1, 0);
    vector<ll> sum(n + 1, 0);
    vector<ll> ans(n + 1, 0);

    // Lambda function
    function<void(int, int)> dfs = [&](int node, int parent) -> void {
        sizes[node] = 1;
        sum[node] = 0;

        // int mx = 0;

        for (int child : adj[node]) {
            if (child != parent) {
                dfs(child, node);

               sizes[node]+=sizes[child];
               sum[node]+=sum[child]+sizes[child];
            }
        }
    };



    auto change = [&] (int node,int child) {

        sum[node]-=sum[child]+sizes[child];

        sizes[node]-=sizes[child];

        sizes[child]+=sizes[node];

        sum[child] += sum[node]+sizes[node];

    };



    function<void(int,int)> reroot=[&] (int node,int parent){
        ans[node] = sum[node];

        for(int child:adj[node])
            if(child!=parent){
                change(node,child);
                reroot(child,node);
                change(child,node);
            }
    };



    dfs(1, 0);


    reroot(1,0);


    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }

   

    return 0;
}


