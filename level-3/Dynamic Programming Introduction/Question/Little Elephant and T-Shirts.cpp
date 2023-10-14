#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define fr(a, b) for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL << 60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll, pair<ll, ll>>
#define fast_io                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)
using namespace std;

#define mod 1000000007

bool people[11][101];
void in(int n)
{
  string s;
  cin.ignore();
  for (int i = 0; i < n; i++)
  {
    getline(cin, s);
    stringstream in(s);
    int a;
    while (in >> a)
    {
      people[i + 1][a] = 1;
    }
  }
}

ll dp[101][1025];
string s1, s2;

ll solve(int shirt, int mask, int n)
{

  if (mask == ((1 << n) - 1))
    return 1;

  if (shirt > 100)
    return 0;

  if (dp[shirt][mask] != -1)
    return dp[shirt][mask];

  ll ans = 0;

  for (int i = 1; i <= n; i++)
  {
    if ((mask & (1 << (i - 1))) != 0)
      continue;
    if (people[i][shirt])
    {
      int temp_msk = (mask | (1 << (i - 1)));
      ans = (ans + solve(shirt + 1, temp_msk, n)) % mod;
    }
  }

  ans = (ans + solve(shirt + 1, mask, n)) % mod;

  return dp[shirt][mask] = ans;
}

int main()
{
  fast_io;

  ll n;
  int t;
  cin >> t;

  while (t--)
  {


    cin >> n;
    memset(people, 0, sizeof people);
    memset(dp, -1, sizeof dp);
    in(n);
    cout << solve(1, 0, n) << '\n';

    
  }

  return 0;
}
