#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9 + 7;

int x[200003];

int main()
{

  string a, b;
  cin >> a >> b;
  for (auto i = 0; i < b.size(); i++)
    x[i + 1] = x[i] + (b[i] - '0');

  int l = b.size() - a.size() + 1;
  long long ans = 0;

  for (auto i = 0; i < a.size(); i++)
  {
    if (a[i] == '0')
      ans += abs(x[i] - x[i + l]);
    else
      ans += l - abs(x[i] - x[i + l]);
  }
  cout << ans;
}

