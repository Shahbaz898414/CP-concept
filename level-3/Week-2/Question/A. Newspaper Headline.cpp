#include <bits/stdc++.h>
using namespace std;

#define ll long long
// 
void solve()
{
    string s, t;
    cin >> s >> t;

    ll n = s.length();

    ll m = t.length();

    set<int> posn[26];

    for (int i = 0; i < n; i++)
        posn[s[i] - 'a'].insert(i);

    int ans = 1, lastindex = -1;

    for (int i = 0; i < m; i++)
    {

        int ch = t[i] - 'a';
        if (posn[ch].size() == 0)
        {
            cout << -1 << endl;
            return;
        }

        auto it = posn[ch].upper_bound(lastindex);

        if (it == posn[ch].end())
            ans++, lastindex = *posn[ch].begin();

        else
            lastindex = *it;
    }

    cout << ans << endl;
}

int main()
{

   

    solve();

    return 0;
}
