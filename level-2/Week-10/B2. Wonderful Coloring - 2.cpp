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
#define all(s) s.begin(), s.end()
#define sz(x) (int)x.size()
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

// ll m = 998244353;

// long long erfd(long long a, long long b)
// {
//   if (b == 0)
//     return 1;
//   long long ans = erfd(a, b / 2);
//   if (b % 2)
//     return (ans % m * ans % m * a) % m;
//   else
//     return ans % m * ans % m;
// }

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

bool possible(long long mid, vector<int> s, long long k, int r)
{
  long long sum = 0;
  vector<long long> v(s.begin(), s.end());

  int n = v.size();

  for (int i = 0; i <= r; i++)
  {
    sum += 1ll * v[i];
  }

  for (int i = 0; i < n; i++)
  {
    /* code */
    if (i - r - 1 >= 0)
      sum += 1ll * v[i - r - 1];
    if (i + r < n and i != 0)
      sum += 1ll * v[i + r];

    if (sum < mid)
    {
      v[min(n - 1, i + r)] += (mid - sum);

      k -= (mid - sum);
      sum = mid;
      if (k < 0)
        return 0;
    }
  }

  return 1;
}

long long maxPower(vector<int> &v, int r, int k)
{
  int n = v.size();
  long long lo = 0, hi = 1e5, res = 0;

  while (lo <= hi)
  {
    long long mid = (lo + hi) / 2;
    if (possible(mid, v, k, r))
    {
      res = mid;
      lo = mid + 1;
    }
    else
      hi = mid - 1;
  }

  return res;
}

int32_t main()
{

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
  {

    int n, r, k;
    cin >> n  >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
      /* code */
      cin >> a[i];
    }

    vector<vector<int>> pos(n);

    for (int i = 0; i < n; i++)
    {
      /* code */
      pos[a[i] - 1].pb(i);
    }

    sort(all(pos), [&](vector<int> a, vector<int> b)
         { return sz(a) > sz(b); });

    int l = 0, h = n;

    vector<int> ans;

    auto f = [&](int mid) -> bool
    {
      vector<int> tempans(n);
      int cnt = 0;
      vector<int> rem;
      for (int i = 0; i < n; i++)
      {
        if (sz(pos[i]) >= k)
        {
          for (int j = 0; j < k; j++)
          {
            tempans[pos[i][j]] = j + 1;
          }
          cnt++;
        }
        else
        {
          for (int j = 0; j < sz(pos[i]); j++)
          {
            rem.pb(pos[i][j]);
          }
        }
      }
      for (int i = 0; i <= sz(rem) - k; i += k)
      {
        for (int j = 0; j < k; j++)
        {
          tempans[rem[i + j]] = j + 1;
        }
      }
      if (cnt >= mid)
      {
        ans = tempans;
      }
      return cnt >= mid;
    };

    while (l <= h)
    {
      int mid = (l + h) / 2;
      if (f(mid))
      {
        l = mid + 1;
      }
      else
      {
        h = mid - 1;
      }
    }
    for (auto it : ans)
    {
      cout << it << " ";
    }

    cout << endl;
  }

  return 0;
}
