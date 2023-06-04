#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main()
{

  int n, k, q;
  cin >> n >> k >> q;
  vector<ll> v(n + 1, 0);
  vector<ll> bt(n + 1, 0);
  for (int i = 0; i < n; i++)
  {
    ll x, y;
    cin >> x >> y;
    v[x]++;
    v[y + 1]--;
  }

  for (int i = 0; i < n + 1; i++)
  {

    cout << v[i] << " ";
  }

  cout << endl;

  ll sum = 0;

  for (int i = 0; i < n; i++)
  {
    /* code */
    sum += v[i];
    bt[i] = sum;
  }
}
