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
        ll n,x;cin>>n>>x;

        vector<ll>  degree(n+1);

        for (ll i =1; i < n; i++)
        {
          /* code */
          ll a,b;cin>>a>>b;
          degree[a]++;
          degree[b]++;
        }

        if(degree[x]<=1)  cout<<"Ayush"<<endl;
        else {
          if(n%2==1)  cout<<"Ashish"<<endl;
          else cout<<"Ayush"<<endl;
        }
        




    }
    return 0;
}

