

#include <bits/stdc++.h>
using namespace std;

void solve()
{
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        long long int arr[n + 1];
        vector<vector<long long int>> vex(k + 1);
        vector<long long int> brr(k + 1, 0);

        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        for (int i = 1; i <= n; i++)
        {
            vex[arr[i]].push_back(i - brr[arr[i]] - 1ll);
            brr[arr[i]] = i;
        }

        long long int minn = INT_MAX;
        for (int i = 1; i <= k; i++)
        {
            vex[i].push_back(n - brr[i]);
            sort(vex[i].begin(), vex[i].end());
            reverse(vex[i].begin(), vex[i].end());
            long long int res = vex[i][0] / 2;
            if (vex[i].size() >= 2)
            {
                res = max(res, vex[i][1]);
            }
            minn = min(minn, res);
        }

        cout << minn << endl;
    }
    return 0;
}
