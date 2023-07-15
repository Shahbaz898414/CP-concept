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
        cin >> arr[i];

    for (ll i = 0; i < n; i++)
    {
        if (arr[i] > k)
        {

            if (arr[i] % k == 0)
            {
                arr[i] = 0;
                continue;
            }

            store = arr[i] / k;
            rem = (arr[i] % k);
            // arr[i]-=rem;
            // arr[i]+=k;

            store++;

            // cout<<store<<" "<<arr[i]<<endl;
            arr[i] = min(rem, abs(store * k) - arr[i]);
        }
    }

    for (ll i = 0; i < n; i++)
    {
        /* code */
        g += arr[i];
    }

    // cout<<endl;

    cout << g << endl;
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
