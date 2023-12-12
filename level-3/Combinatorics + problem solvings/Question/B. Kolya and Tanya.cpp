#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9 + 7;

int main()
{

  long long a = 1, b = 1;
  int n, i;
  cin >> n;
  for (i = 1; i <= n; i++)
  {
    a = (a * 27) % mod;
    b = (b * 7) % mod;
  }
  cout << (a - b + mod) % mod;
}
