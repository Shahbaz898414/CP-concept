#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long long int

int main()
{

  ll n, k;
  cin >> n;
  string s, t;
  cin >> s >> t;

  int c = 0, ac = 0, bc = 0;

  // vector<ll> arr(n);

  for (ll i = 0; i < 2 * n; i++)
  {

    // cin >> arr[i];

    if (s[i] == '1')
      ac++;
    if (t[i] == '1')
      bc++;
    if (s[i] == '1' && t[i] == '1')
      c++;
  }

  // vector<ll> vec, cnt(k + 1);

  if (c % 2 == 1)
    c = 1;
  else if (c % 2 == 0)
    c = 0;
  if (bc > ac + c)
    c++;
  if (ac + c > bc)
    cout << "First";
  if (ac + c < bc)
    cout << "Second";
  if (ac + c == bc)
    cout << "Draw";

  return 0;
}
