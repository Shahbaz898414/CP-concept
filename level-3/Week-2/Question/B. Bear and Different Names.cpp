#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long long int

int main()
{

  ll n, m, k;
  cin >> n >> k;
  char s[50];

  for (int i = 0; i < k - 1; i++)
  {
    /* code */
    s[i] = i;
  }

  string q;
  cin >> q;

  for (int i = k - 1; i < n; i++)
  {
    /* code */
    cin >> q;
    if (q == "NO")
    {
      s[i] = s[i - k + 1];
    }
    else
      s[i] = i;
  }

  for (int i = 0; i < n; i++)
  {
    
    if (s[i] < 26)
      cout << char(s[i] + 65) << " ";
    else
      cout << 'A' << char(s[i] - 26 + 97) << " ";
  }

  return 0;
}
