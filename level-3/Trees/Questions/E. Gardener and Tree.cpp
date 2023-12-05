#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;

    vector<set<ll>> graph(n);
    int connect[n] = {0};

    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> u >> v;
        u--;
        v--;

        graph[u].insert(v);
        graph[v].insert(u);
        connect[v]++;
        connect[u]++;
    }

    set<pair<int, int>> s;

    for (int i = 0; i < n; i++) {
        s.insert({connect[i], i});
    }

    int left = n;

    vector<ll> v;

    while (left and k--) {

        v.clear();

        for (auto it : s) {
            if (it.first > 1)
                break;

            v.push_back(it.second);
        }

        left -= v.size();

        for (auto u : v) {
          // 
            s.erase(s.find({connect[u], u}));
            connect[u]--;

            for (auto v : graph[u]) {
                s.erase(s.find({connect[v], v}));
                connect[v]--;

                s.insert({connect[v], v});

                graph[v].erase(u);
            }
        }
    }

    cout << left << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
int t;cin>>t;
while(t--)
    solve();

    return 0;
}
