
#include <bits/stdc++.h>
using namespace std;
#define ll long long



struct segtree {
    const ll NO_OP = 0;
    const ll EMPTY = LLONG_MAX;

    struct node {
        ll modify;
        ll value;
    };

    int size;
    vector<node> tree;

    ll _modify(ll a, ll b, ll len) {
        if (b == NO_OP) return a;
        return a + b;
    }

    ll _get(ll a, ll b) {
        return min(a, b);
    }

    void build(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2*size, {0, 0});
    }

    void propagate(int x, int lx, int rx) {
        if (tree[x].modify == NO_OP || rx == lx + 1) return;
        int m = (lx + rx) / 2;
        tree[2*x+1].modify = _modify(tree[2*x+1].modify, tree[x].modify, 1);
        tree[2*x+1].value = _modify(tree[2*x+1].value, tree[x].modify, m - lx);
        tree[2*x+2].modify = _modify(tree[2*x+2].modify, tree[x].modify, 1);
        tree[2*x+2].value = _modify(tree[2*x+2].value, tree[x].modify, rx - m);
        tree[x].modify = NO_OP;
    }

    void update(int l, int r, int v) {
        update(l, r, v, 0, 0, size);
    }


    void update(int l, int r, int v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r) return;
        if (rx <= l) return;
        if (lx >= l && rx <= r) {
            tree[x].modify = _modify(tree[x].modify, v, 1);
            tree[x].value = _modify(tree[x].value, v, rx - lx);
        } else {
            int m = (lx + rx) / 2;
            update(l, r, v, 2*x+1, lx, m);
            update(l, r, v, 2*x+2, m, rx);
            tree[x].value = _get(tree[2*x+1].value, tree[2*x+2].value);
        }
    }


    ll get(int l, int r) {
        return get(l, r, 0, 0, size);
    }


    ll get(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l) return EMPTY;
        if (lx >= l && rx <= r) return tree[x].value;
        int m = (lx + rx) / 2;
        ll v1 = get(l, r, 2*x+1, lx, m);
        ll v2 = get(l, r, 2*x+2, m, rx);
        return _get(v1, v2);
    }


};




int main(void) {


    int n, m;

    
    cin >> n >> m;


    segtree st;


    st.build(n);

    int cmd, l, r, v;

    while (m--) {

        cin >> cmd;
        if (cmd == 1) {
            cin >> l >> r >> v;
            st.update(l, r, v);
        } else {
            cin >> l >> r;
            cout << st.get(l, r) << endl;
        }

    }

    return 0;
}



/*


Hi,

I hope this message finds you well! I came across the Software Development Intern (https://docs.google.com/forms/d/e/1FAIpQLSelAjzPgaV9mNsNtN2okz78E2HVrqhWcj5Gin9RT5YxpfRMhw/viewform) at Zeta. As an aspiring Software Engineer, I admire the company's innovative work. If possible, could you kindly refer me? I'd greatly appreciate it!

Best regards,
Shahbaz Khan


*/