#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define Time cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define pb push_back
#define mp make_pair
#define line cout << endl;
#define ff first
#define ss second
#define vi vector<int>
#define no cout << "NO" << endl;
#define yes cout << "YES" << endl;
#define printv(v)                      \
  for (int i = 0; i < (v.size()); i++) \
  {                                    \
    cout << v[i] << " ";               \
  }                                    \
  line;
#define onesbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define sp(x, y) fixed << setprecision(y) << x
#define w(x) \
  int x;     \
  cin >> x;  \
  while (x--)
#define tk(x) \
  int x;      \
  cin >> x;
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
#define debug(x)     \
  cerr << #x << " "; \
  _print(x);         \
  cerr << endl;
#else
#define debug(x)
#endif
template <class T>
void _print(T t)
{
  cerr << t;
}

template <class T, class V>
void _print(pair<T, V> p)
{
  cerr << "{";
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
  cerr << "}";
}

template <class T>
void _print(vector<T> v)
{
  cerr << "[ ";
  for (T i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}

template <class T>
void _print(vector<vector<T>> v)
{
  cerr << "[\n";
  for (int l = 0; l < v.size(); l++)
  {
    {
      for (int k = 0; k < v[l].size(); k++)
        cerr << v[l][k] << " ";
    }
    cerr << "\n";
  }
  cerr << "]";
}

template <class T, class V>
void _print(map<T, V> v)
{
  cerr << "[ ";
  for (auto i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}

template <class T>
void _print(set<T> v)
{
  cerr << "[ ";
  for (T i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}

// const long long inf = 1e18;
// const int MOD = 998244353;
// const int MAX = 1e6;

bool isValid(string s)
{
  int len = s.size();
  for (int i = 0; i < len / 2; i++)
  {
    if (s[i] != s[len - 1 - i])
      return false;
  }
  return true;
}

void rotateMatrix(vector<vector<int>> &v, int n)
{
  for (int i = 0; i < n / 2; i++)
  {
    for (int j = i; j < n - i - 1; j++)
    {
      int ptr = v[i][j];
      v[i][j] = v[n - 1 - j][i];
      v[n - 1 - j][i] = v[n - 1 - i][n - 1 - j];
      v[n - 1 - i][n - 1 - j] = v[j][n - 1 - i];
      v[j][n - 1 - i] = ptr;
    }
  }
}

ll ml = 998244353;

long long erfd(long long a, long long b)
{
  if (b == 0)
    return 1;
  long long ans = erfd(a, b / 2);
  if (b % 2)
    return (ans % ml * ans % ml * a) % ml;
  else
    return ans % ml * ans % ml;
}

const ll N = 4e5 + 5;
ll fact[N + 1];

void precomp()
{
  fact[0] = 1;

  for (ll i = 0; i <= N; i++)
  {

    fact[i] = (fact[i] * i) % mod;
  }
}

ll power(ll base, ll x)
{
  if (x < 0)
  {
    return 0;
  }

  ll ans = 1;
  while (x)
  {
    if (x % 2 == 0)
    {
      base = (base * base) % mod;
      x = x / 2;
    }
    else
    {
      ans = (ans * base) % mod;
      x--;
    }
  }

  return ans;
}

ll ncr(ll n, ll r)
{
  if (r > n)
    return 0;

  ll numo = fact[n];
  ll demo = (fact[r] * fact[n - r]) % mod;
  ll ans = (numo * power(demo, mod - 2)) % mod;

  return ans;
}

int f(int d)
{
  for (int j = 2; j <= sqrt(d); j++)
  {
    if (d % j == 0)
      d = f(d + 1);
  }

  return d;
}

unsigned long long gcd(unsigned long long x, unsigned long long y)
{
  if (y == 0)
    return x;
  return gcd(y, x % y);
}

int s[N], e[N], cost[N];

// int dp[100][100001];

void solve()
{
  ll n;
  cin >> n;

  pair<int, pair<int, int>> arr[n];

  for (ll i = 0; i < n; i++)
  {
    int l, r, p;

    cin >> l >> r >> p;

    arr[i] = make_pair(l, make_pair(r, p));
  }

  sort(arr, arr + n);

  int dp[n + 1];

  for (ll i = n; i >= 0; i--)
  {

    if (i == n)
    {
      dp[i] = 0;
    }
    else
    {

      dp[i] = dp[i + 1];
      int next = arr[i].second.first;

      auto it = upper_bound(arr, arr + n, make_pair(next, make_pair(1e9, 1e9))) - arr;

      dp[i] = max(dp[i], arr[i].second.second + dp[it]);
    }
  }

  cout << dp[0] << endl;
}

int32_t main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--)
    solve();
}