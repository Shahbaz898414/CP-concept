#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

class SegTree
{
public:
    const int N = 5000005;
    int n; // array size
    ll *sum_tree;
    ll res = 0;

    SegTree(vector<int> &arr, int n)
    {
        sum_tree = new ll[N];
        this->n = n;
        build(arr);
    }

    void build(vector<int> &arr)
    {
        for (int i = 0; i < n; ++i)
        {
            sum_tree[n + i] = arr[i];
        }

        for (int i = n - 1; i > 0; --i)
        {
            sum_tree[i] = sum_tree[i << 1] + sum_tree[i << 1 | 1];
        }
    }

    void result(int l, int r)
    {
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
            {
                res = res + sum_tree[l++];
            }

            if (r & 1)
            {
                res = res + sum_tree[--r];
            }
        }
    }

    ll getSum(int l, int r)
    {
        if (l > r)
            return 0;
        res = 0;
        result(l, r);

        return res;
    }

    void update(int p, ll value)
    { // set value at position p
        for (sum_tree[p += n] = value; p > 1; p >>= 1)
        {
            sum_tree[p >> 1] = (sum_tree[p] + sum_tree[p ^ 1]);
        }
    }
};

void solve()
{
    string s;
    cin >> s;

    int n = s.size();

    vector<int> closing(n, -1);
    set<int> open;
    vector<int> vals(n);

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            open.insert(i);
        }
        else
        {
            if (open.size())
            {
                closing[*open.rbegin()] = i;
                open.erase(*open.rbegin());
                vals[i] = 1;
            }
        }
    }

    SegTree sgt(vals, n);

    int q;
    cin >> q;

    vector<vector<pair<int, int>>> queries(n);

    for (int i = 0; i < q; i++)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        queries[l].pb({r, i});
    }

    vector<int> ans(q);

    for (ll l = 0; l < n; l++)
    {
        for (auto [r , k] : queries[l])
        {
            ans[k] = 2 * sgt.getSum(l, r + 1);
        }

        if (s[l] == '(')
        {
            if (*open.begin() == l)
                open.erase(l);

            if (closing[l] != -1)
            {
                if (!open.size() || *open.begin() > closing[l])
                {
                    vals[closing[l]] = 0;
                    sgt.update(closing[l], 0);
                }
                else
                {
                    int i = *(--open.lower_bound(closing[l]));
                    open.erase(i);
                    closing[i] = closing[l];
                }
            }
        }
    }



    for (int i = 0; i < q; ++i) {
        cout << ans[i] << endl;
    }


}




int main()
{

    int t;cin>>t;
    while(t--)
    solve();
    return 0;
}
