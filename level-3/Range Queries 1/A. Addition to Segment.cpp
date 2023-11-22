
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct segtree
{
    int size;
    vector<ll> tree;

    void build(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        tree.assign(2 * size, 0);
    }

    void add(int l, int r, int v)
    {
        add(l, r, v, 0, 0, size);
    }

    void add(int l, int r, int v, int x, int lx, int rx)
    {

        if (lx >= r)
            return;
        if (rx <= l)
            return;
        if (lx >= l && rx <= r)
        {
            tree[x] += v;
            return;
        }

        int m = (lx + rx) / 2;

        add(l, r, v, 2 * x + 1, lx, m);

        add(l, r, v, 2 * x + 2, m, rx);
    }

    ll get(int idx)
    {
        return get(idx, 0, 0, size);
    }

    ll get(int idx, int x, int lx, int rx)
    {
        if (rx == lx + 1)
        {
            return tree[x];
        }

        int m = (lx + rx) / 2;
        if (idx < m)
            return get(idx, 2 * x + 1, lx, m) + tree[x];
        else
            return get(idx, 2 * x + 2, m, rx) + tree[x];
    }
};




void solve() {


    int n, m; cin >> n >> m;


    segtree st;


    st.build(n);


    int cmd;
    while (m--)
    {
        cin >> cmd;
        if (cmd == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            st.add(l, r, v);
        }
        else
        {
            int i;
            cin >> i;
            cout << st.get(i) << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}
