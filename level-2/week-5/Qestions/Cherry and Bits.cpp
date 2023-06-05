
/*
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ll n, m;
  cin >> n >> m;

  ll a[n + 1][m + 1];

  for (ll i = 0; i < n; i++)
  {
    for (ll j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }

  vector<vector<int>> ans(n + 1, vector<int>(m + 1, 0));

  ll q;
  cin >> q;
  while (q--)
  {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    ans[x1][y1]++;
    if (x2 + 1 <= n && y2 + 1 <= m)
      ans[x2 + 1][y2 + 1]++;
    if (y2 + 1 <= m)
      ans[x1][y2 + 1]--;
    if (x2 + 1 <= n)
      ans[x2 + 1][y1]--;
  }

  // for (int i = 1; i <= n; i++)
  // {

  //   for (int j = 1; j <= m; j++)
  //   {

  //     cout << ans[i][j] << " ";
  //   }

  //   cout << endl;
  // }

  // cout << endl;

  // for (int i = 0; i <= m; i++)
  // {
  //   for (int j = 1; j <= n; j++)
  //   {
  //     cout<<ans[j][i]<<' ';
  //   }
  //   cout<<endl;
  // }

  // cout << endl;
  // for (int i = 0; i <= n; i++)
  // {
  //   for (int j = 1; j <= m; j++)
  //   {
  //   cout<<ans[j][i]<<' ';
  //   }
  //   cout<<endl;
  // }

  // cout << endl;


  // for (int i = 1; i <= n; i++)
  // {

  //   for (int j = 1; j <= m; j++)
  //   {

  //     cout << ans[i][j] << " ";
  //   }

  //   cout << endl;
  // }

  // cout << endl;



    for(int i = 0 ; i <= m ; i++){
        for(int j = 1 ; j <= n ; j++){
            ans[j][i] += ans[j-1][i];
        }
    }
    for(int i = 0 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            ans[i][j] += ans[i][j-1];
        }
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(ans[i][j] % 2 == 0){
                cout<<a[i-1][j-1];
            }
            else{
                cout<<(a[i-1][j-1] ^ 1);
            }
        }
        cout<<endl;
    }


  //   for (int i = 1; i <= n; i++)
  // {

  //   for (int j = 1; j <= m; j++)
  //   {

  //     cout << ans[i][j] << " ";
  //   }

  //   cout << endl;
  // }

  // cout << endl;




}
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, m;
  cin >> n >> m;
  int a[n][m];
  // int b[n+1][m+1];
  vector<vector<int>> b(n + 1, vector<int>(m + 1, 0));
  char c;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> c;
      a[i][j] = c - '0';
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }

  
  int q;
  cin >> q;
  while (q--)
  {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    b[x1][y1]++;
    if (x2 + 1 <= n && y2 + 1 <= m)
      b[x2 + 1][y2 + 1]++;
    if (y2 + 1 <= m)
      b[x1][y2 + 1]--;
    if (x2 + 1 <= n)
      b[x2 + 1][y1]--;
  }
  for (int i = 0; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      b[j][i] += b[j - 1][i];
    }
  }
  for (int i = 0; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      b[i][j] += b[i][j - 1];
    }
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (b[i][j] % 2 == 0)
      {
        cout << a[i - 1][j - 1];
      }
      else
      {
        cout << (a[i - 1][j - 1] ^ 1);
      }
    }
    cout << endl;
  }
  return 0;
}