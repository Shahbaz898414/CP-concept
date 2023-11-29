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


Dear Aniket Bajpa,

I hope this message finds you well. My name is shahbaz khan, and I am writing to you as a candidate who has recently qualified for the next round in the LimeChat Front-End Developer hiring process.

Firstly, I want to express my gratitude for the opportunity to progress in the selection process. I am enthusiastic about the prospect of contributing to LimeChat's dynamic team and innovative projects.

I have received communication regarding the assessment test scheduled for tomorrow, November 29, 2023, from 8:00 PM to 9:00 PM IST. However, I have not yet received the link to access the test. I understand the importance of this phase in the hiring process and am keen to participate.

Could you kindly provide me with the necessary link or guide me on the next steps to ensure I can take the assessment tomorrow as scheduled?

I appreciate your attention to this matter and am looking forward to the opportunity to demonstrate my skills and passion for contributing to LimeChat's success.

Thank you for your time and consideration.

Warm regards,

Shahbaz Khan
7710968756
shahbaz898khan@gmail.com


*/