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

    vector<int> depth(n + 1, 0);
    vector<int> diameter(n + 1, 0);
    vector<int> ans(n + 1, 0);

    // Lambda function
    function<void(int, int)> dfs = [&](int node, int parent) -> void {
        depth[node] = 1;
        diameter[node] = 1;

        int mx = 0;

        for (int child : adj[node]) {
            if (child != parent) {
                dfs(child, node);

                depth[node] = max(depth[node],1+ depth[child]);
                diameter[node] = max({diameter[node], diameter[child],1 + mx + depth[child]});
                // diameter[node] = max(diameter[node], 1 + mx + depth[child]);

                mx = max(mx, depth[child]);
            }
        }
    };

    dfs(1, 0);

    cout << diameter[1]-1 << endl;

    return 0;
}


/*


Today was my 53th day out of the 100 days  hard challenge.
So today, I solved 5 problems .


1. B. Death's Blessing (https://codeforces.com/problemset/problem/1749/B).


2. B. BAN BAN (https://codeforces.com/problemset/problem/1747/B).


3. C. Stripes (https://codeforces.com/problemset/problem/1742/C)


4. A. Ela Sorting Books (https://codeforces.com/problemset/problem/1737/A).


5. B. Tea with Tangerines (https://codeforces.com/problemset/problem/1735/B).


#100dayschallenge #challenge #consistency #Cp #lessons  #learning #setmentTree



*/
