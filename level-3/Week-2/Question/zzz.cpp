#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long long int

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    ll g = 0;

    ll rem = 0, store = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (ll i = 0; i < n; i++)
    {
        if (arr[i] < k)
        {
            g += arr[i];
        }
        else
        {
            store = arr[i];
            rem = (arr[i] % k);
        }
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
