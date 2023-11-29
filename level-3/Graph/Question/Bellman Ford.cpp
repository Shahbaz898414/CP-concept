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


  if(x != -1){
    return {};
  }


  return dist;
  
}


void  printPath(int dest,int src ,vector<int>& parent){
  
  
  vector<int> path;


  while(dest!=src) {


    path.push_back(dest);


    dest=parent[dest];


  }


  path.push_back(dest);


  reverse(path.begin(),path.end());


}



// O(VlogV + ElogV)
// Single Source Shortest Path

void Dijkstra(int s, int n, vector<ll> &dist, vector<int> &parent, vector<pair<int, ll>> *adj) {
	dist.assign(n, INF);
	parent.assign(n, -1);
	dist[s] = 0;
	priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;


	q.push({0, s});
	while (!q.empty()) {
		pair<ll, int> here = q.top();
		q.pop();
		int v = here.ss;
		ll d_v = here.ff;
		if (d_v != dist[v])
			continue;
		for (auto edge : adj[v]) {
			if (dist[v] + edge.ss < dist[edge.ff]) {
				dist[edge.ff] = dist[v] + edge.ss;
				parent[edge.ff] = v;
				q.push({dist[edge.ff], edge.ff});

        parent[edge.ff]=v;

			}
		}
	}
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


/*


Today was my 56th day out of the 100 days  hard challenge.
So today, I solved 5 problems .


1. 1727. Largest Submatrix With Rearrangements (https://leetcode.com/problems/largest-submatrix-with-rearrangements/description/?envType=daily-question&envId=2023-11-26).


2. T191. Number of 1 Bits (https://leetcode.com/problems/number-of-1-bits/description/?envType=daily-question&envId=2023-11-29).


3.143. Reorder List (https://leetcode.com/problems/reorder-list/description/)


4. 160. Intersection of Two Linked Lists (https://leetcode.com/problems/intersection-of-two-linked-lists/description/).


5. 25. Reverse Nodes in k-Group (https://leetcode.com/problems/reverse-nodes-in-k-group/description/).


#100dayschallenge #challenge #consistency #Cp #lessons  #learning #setmentTree


*/