  
#include <bits/stdc++.h>
#define int long long

using namespace std;

pair<const int, const int> mod = { 1e9 + 7,1e9 + 9 };

pair<int, int> get_hash(string s) {
    int n = s.size();

    pair<int, int> h = { 0,0 };

    for (int i = 0; i < n; i++) {
        h.first = (h.first * 31 + (s[i] - 'a' + 1)) % mod.first;
        h.second = (h.second * 53 + (s[i] - 'a' + 1)) % mod.second;

    }
    return h;
}


vector<int>  rabin_karp(string s, string t) {
    int n = s.size(), m = t.size();
    pair<int, int> p = { 1,1 };

    for (int i = 0; i < m - 1; i++) {
        p.first = (p.first * 31) % mod.first;
        p.second = (p.second * 53) % mod.second;
    }
    vector<int> pos;
    pair<int, int> ht = get_hash(t);

    pair<int, int> hs = get_hash(s.substr(0, m));

    if (hs == ht) {
        pos.push_back(0);
    }


    for (int l = 1, r = m; r < n; l++, r++) {
        int del = ((s[l - 1] - 'a' + 1) * p.first) % mod.first;
        int add = s[r] - 'a' + 1;
        hs.first = ((hs.first - del + mod.first) * 31 + add) % mod.first;
        del = ((s[l - 1] - 'a' + 1) * p.second) % mod.second;
        add = s[r] - 'a' + 1;
        hs.second = ((hs.second - del + mod.second) * 53 + add) % mod.second;
        if (hs == ht) pos.push_back(l);
    }

    return pos;

}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;cin >> s >> t;
    vector<int> v = rabin_karp(s, t);
    //    cout<<size(rabin_karp(s,t))<<endl;
    cout << v.size() << endl;
}


/*
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int base = 30, mod = 1000000007;
const int N = 1e6 + 5;
vector<int> pw(N), inv(N);


int add(int a, int b, int mod) {
    int val = (a % mod + b % mod) % mod;
    if (val < 0)
        val += mod;
    return val;
}


int mult(int a, int b, int mod) {
    long long val = (a * 1LL * b) % mod;
    if (val < 0)
        val += mod;
    return val;
}

int bp(int a, int b, int mod) {
    int res = 1;
    while (b > 0)
    {
        if (b % 2 != 0)
            res = mult(res, a, mod);
        a = mult(a, a, mod);
        b >>= 1;
    }
   
    return res;
}

void precal()
{
    pw[0] = 1;
    inv[0] = 1;
    int pw_inv = bp(base, mod - 2, mod);
    for (int i = 1; i < N; i++)
    {
        pw[i] = mult(pw[i - 1], base, mod);
        inv[i] = mult(inv[i - 1], pw_inv, mod);
    }
}

class string_hash
{
public:
    vector<int> hash;
    int n;

    string_hash(string s)
    {
        n = s.size();
        hash.resize(s.size() + 5);
        hash[0] = mult((s[0] - 'a' + 1), 1, mod);
        for (int i = 1; i < s.size(); i++)
            hash[i] = add(hash[i - 1], mult(s[i] - 'a' + 1, pw[i], mod), mod);
    }

    int range(int i, int j)
    {
        int val = add(hash[j], (i == 0) ? -0 : -hash[i - 1], mod);
        int res = mult(val, inv[i], mod);
        return res;
    }

    int tut()
    {
        return hash[n - 1];
    }
};

int main()
{
    string s, c;
    cin >> s >> c;
    precal();
    string_hash a1(s);
    string_hash a2(c);
    int ans = 0;
    for (int i = 0; i <= s.size() - c.size(); i++)
    {
        int h1 = a1.range(i, i + c.size() - 1);
        if (h1 == a2.tut())
            ans += 1;
    }
    cout << ans << endl;
    return 0;
}

*/
