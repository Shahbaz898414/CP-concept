#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{

    // int t;cin>>t;

    // while(t--) {

    // }

    ll n;
    cin >> n;

    vector<ll> arr[n];

    vector<ll> v;

    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            ll y;
            cin >> y;
            arr[i].push_back(y);
            v.push_back(y);
        }
    }

    sort(v.begin(), v.end());

    int split = n;

    for (int i = 0; i < n; i++)
    {

        int j = arr[i].size();
        for (int z = 0; z < j - 1; z++)
        {

            int k = lower_bound(v.begin(), v.end(), arr[i][z]) - v.begin();

            if (k == v.size() - 1)
            {
                split++;
            }
            else if (arr[i][z + 1] != v[k + 1])
            {
                split++;
            }
        }
    }

    cout << (split - n) << " " << (split - 1) << endl;

    return 0;
}

// broken_soul