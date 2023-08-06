#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long long int

int convert(char s)
{
  if (s == '2')
    return 5;
  else if (s == '9')
    return 6;
  else
    return s - '0';
}

int main()
{

  ll n, k;
  // cin >> n;
  string s, t;
  cin >> s >> t;

  int c = 0, ac = 0, bc = 0;
  int a[30] = {0}, b[46] = {0}, ans = INT_MAX;
  // vector<ll> arr(n);

  for (auto it : s)
  {
    a[convert(it)]++;
  }

  for (auto it : t)
  {
    b[convert(it)]++;
  }

  for (int i = 0; i <= 9; i++)
  {
    /* code */
    if (a[i])
      ans = min(ans, b[i] / a[i]);
  }

  cout << ans;

  return 0;
}
