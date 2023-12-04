#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
// #include "algo/debug.h"
#else
#define dbg(...) ;
#define debug(...) ;
#define crndl ;
#endif

void solve()
{

  int n, k, mn = -1, i;
  cin >> n;
  int arr[n + 1];
  for (i = 1; i <= n; i++)
    cin >> arr[i];
  for (i = 1; i <= n; i++)
  {
    int j = i;
    k = 1;
    while (arr[j] != -1)
    {

      cout<<1<<" ";
      j = arr[j];
      k++;
    }

    cout<<endl;
    mn = max(k, mn);
  }

  cout << mn << endl;
}

int32_t main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

// #ifndef ONLINE_JUDGE
//   freopen("io/input.txt", "r", stdin);
//   freopen("io/output.txt", "w", stdout);
//   freopen("io/error.txt", "w", stderr);
// #endif

  int t = 1;
  // cin >> t;

  for (int _t = 1; _t <= t; _t++)
  {
    // debug(Testcase, _t);
    solve();
    // crndl;
  }

  return 0;
}

