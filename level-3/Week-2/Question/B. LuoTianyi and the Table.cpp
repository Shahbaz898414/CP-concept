#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{

  int t;
  cin >> t;

  while (t--)
  {
    int n, m;
    cin >> n >> m;

    int arr[2100000];

    for (int i = 0; i < n * m; i++)
    {
      cin >> arr[i];
    }

    sort(arr, arr + n * m);
    if (n < m) swap(n, m);

    long long ans = max((n - 1) * m * (arr[n * m] - arr[1]) + (m - 1) * (arr[n * m] - arr[2]), (n - 1) * m * (arr[n * m] - arr[1]) + (m - 1) * (arr[n * m - 1] - arr[1]));

    cout << ans << "\n";
  }

  return 0;
}
