#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long long int

string a;
vector<int> v[200010];

int main()
{
  cin >> a;
  int c = 0, k = 0;

  for (int i = 0; i < a.length(); i++)
  {
    if (a[i] == '0')
      v[c++].push_back(i + 1);
    else
    {
      if (c == 0)
      {
        cout << -1;
        return 0;
      }

      v[--c].push_back(i + 1);
    }

    k = max(k, c);
  }

  if (k != c)
  {
    cout << -1;
    return 0;
  }

  cout << c << endl;

  for (int i = 0; i < c; i++)
  {
    cout << v[i].size() << " ";

    for (int j = 0; j < v[i].size(); j++)
      cout << v[i][j] << " ";

    cout << endl;
  }
}