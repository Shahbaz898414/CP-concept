#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    sort(a.begin(), a.end());
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        int l, r;
        cin >> l >> r;

        auto itl = lower_bound(a.begin(), a.end(), l);
        auto itr = upper_bound(a.begin(), a.end(), r);

        cout << itr - itl << " ";
    }
    cout << '\n';
}