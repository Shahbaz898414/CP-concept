#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAXN 202020

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

    vector<int> sizes(n + 1, 0);
    vector<int> sum(n + 1, 0);
    vector<int> ans(n + 1, 0);

    // Lambda function
    function<void(int, int)> dfs = [&](int node, int parent) -> void {
        sizes[node] = 1;
        sum[node] = 0;

        int mx = 0;

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


