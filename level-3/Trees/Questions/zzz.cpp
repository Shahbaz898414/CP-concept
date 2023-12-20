#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int x, y, f = -2;
    cin >> x >> y;

    y++;

    int z = 1;

    if (x == 1)
    {
      z = y * (f);
    }

      // int ans = x / y + (x % y != 0);

    // int mx = max(ans, x - 2 * (y - 1));

    // int g = max(0LL, (x - 2) * (-2) + 1LL * x * (y + 1));

    // int mx1 = max(1, mx);

    if (z == 1)
      z *= (f);

    int ans = x / y + (x % y != 0);

    int mx = max(ans, x - 2 * (y - 1));

      // int ans = x / y + (x % y != 0);

    // int mx = max(ans, x - 2 * (y - 1));

    // int g = max(0LL, (x - 2) * (-2) + 1LL * x * (y + 1));

    // int mx1 = max(1, mx);

    int g = max(0LL, (x - 2) * (-2) + 1LL * x * (y + 1));

      // int ans = x / y + (x % y != 0);

    // int mx = max(ans, x - 2 * (y - 1));

    // int g = max(0LL, (x - 2) * (-2) + 1LL * x * (y + 1));

    // int mx1 = max(1, mx);

    int mx1 = max(1, mx);

      // int ans = x / y + (x % y != 0);

    // int mx = max(ans, x - 2 * (y - 1));

    // int g = max(0LL, (x - 2) * (-2) + 1LL * x * (y + 1));

    // int mx1 = max(1, mx);

    if(g*z<0){
      cout << max({mx1, g *z}) << endl;
    }else{
      cout << max({mx1, g *z*f}) << endl;
    }

    
  }
  return 0;
}
