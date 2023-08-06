#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int M = 1e9 + 7;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (ll i = 0; i < n; i++)
        {

            cin >> b[i];
        }

        ll l = 0, r = -1;

        // ll maxi = LLONG_MIN;

        for (ll i = 0; i < n; i++)
        {

            if (a[i] != b[i])
            {
                l = min(l, i);
                r = max(r, i);
            }
        }

        if (r == -1)
        {
            cout << 0 << endl;
            continue;
        }
        // cout<<r<<" "<<l<<endl;

        cout << r - l + 1 << endl;
    }
    return 0;
}
