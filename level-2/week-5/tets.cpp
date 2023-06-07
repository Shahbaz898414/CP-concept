

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n, q;
    cin >> n >> q;
    vector<long long> s(n + 1, 0L), sd(n + 1, 0L);
    int l, r;
    while (q--)
    {
      cin >> l >> r;
      s[l] += 1L;
      if (r < n)
      {
        s[r + 1] -= 1;
        sd[r + 1] -= (r - l + 1);
      }
    }

    for (int i = 1; i <= n; i++)
    {
      s[i] += s[i - 1];
      sd[i] += (sd[i - 1] + s[i]);
      cout << sd[i] << " ";
    }
    cout << endl;
  }

  return 0;
}