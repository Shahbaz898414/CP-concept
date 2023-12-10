#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> a1, b1;

ll si;
ll bs(ll l, ll h, ll k)
{
    if (l <= h)
    {
        ll m = (l + h) / 2;

        if (b1[m] <= k)
        {
            if (m + 1 <= h)
            {
                if (b1[m + 1] > k)
                {
                    return m;
                }
                else
                {
                    return bs(m + 1, h, k);
                }
            }
            else
            {
                return m;
            }
        }
        else
        {
            return bs(l, m - 1, k);
        }
    }
    else
    {
        return -1;
    }
}


void dfs(ll i, ll a[], ll b[], ll ans[], vector<ll> adj[], bool v[])
{
    v[i] = true;
    if (si == 0)
    {
        a1.push_back(a[i]);
        b1.push_back(b[i]);
        si++;
    }
    else
    {
        a1.push_back(a1[si - 1] + a[i]);
        b1.push_back(b1[si - 1] + b[i]);
        si++;

        ans[i] = bs(0, si - 1, a1[si - 1]);
    }

    ll j, l = adj[i].size();

    for (j = 0; j < l; j++)
    {
        if (v[adj[i][j]] == false)
        {
            dfs(adj[i][j], a, b, ans, adj, v);
        }
    }

    a1.pop_back();
    b1.pop_back();
    si--;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, n, i, j, p;

    cin >> t;

    for (; t--;)
    {
        cin >> n;
        si = 0;
        vector<ll> adj[n + 1];
        bool v[n + 1];
        ll a[n + 1], b[n + 1], ans[n + 1];

        for (i = 0; i <= n; i++)
        {
            v[i] = false;
        }

        a[1] = b[1] = 0;
        for (i = 2; i <= n; i++)
        {
            cin >> p >> a[i] >> b[i];
            adj[i].push_back(p);
            adj[p].push_back(i);
        }

        dfs(1, a, b, ans, adj, v);

        for (i = 2; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}