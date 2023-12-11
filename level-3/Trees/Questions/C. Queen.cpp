#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool dfs(int node, int parent, vector<vector<ll>> &adj, vector<ll> &color, vector<ll> &ones)
{
    bool fl = true;
    for (auto c : adj[node])
    {
        if (c == parent)
            continue;

        if (!dfs(c, node, adj, color, ones))
        {
            fl = false;
        }
    }

    if (fl == true and color[node] == 1)
    {
        ones.push_back(node);
    }

    return color[node] == 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;

    cin >> t;

    for (; t--;)
    {
        ll n;
        cin >> n;

        vector<vector<ll>> adj(n + 1);
        vector<ll> color(n + 1);

        int root;

        for (int i = 1; i <= n; i++)
        {
            int x, y;
            cin >> x >> y;
            if (x == -1)
            {
                root = i;
                continue;
            }

            adj[i].push_back(x);
            adj[x].push_back(i);

            color[i] = y;
        }

        vector<ll> ones;

        dfs(root, -1, adj, color, ones);

        sort(ones.begin(), ones.end());

        if (ones.size() == 0)
            cout << -1 << endl;
        else
        {
            for (auto x : ones)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

/*


#include<iostream>
using namespace std;
int main()
{
    int n,i,x,y;
    cin>>n;
    int z=2,c[n+1]={0};
    for(i=1;i<=n;i++) {
        cin>>x>>y;
        if(y!=1) {
            c[i]=1;
            if(x!=-1)
            c[x]=1;
        }
    }


    for(i=1;i<=n;i++)
        if(c[i]!=1) {
           cout<<i<<" ";
           z=1;
        }

    if(z==2)
      cout<<-1;
}



\*/


/*



666666666666666666666666666666666666666666666666666666666666666666666666666666666666++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++445555555555555555555555555555555555555555545556+696666666666666666666666666666666666666666665854






*/