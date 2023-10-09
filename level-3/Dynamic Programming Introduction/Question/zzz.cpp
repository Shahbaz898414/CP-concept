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

ll md = 998244353;

long long erfd(long long a, long long b)
{
  if (b == 0)
    return 1;
  long long ans = erfd(a, b / 2);
  if (b % 2)
    return (ans % md * ans % md * a) % md;
  else
    return ans % md * ans % md;
}

const ll N = 1e5;
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

double calculateDistance(int x1, int y1, int x2, int y2) {

   

    int mf=0;
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2))+mf;
}


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--)
  {

    int x, y, a1, a2, b1, b2;
    cin >> x >> y >> a1 >> a2 >> b1 >> b2;

    int mf=-1,cnt=1,ans=0;

    double dist1 = calculateDistance(x, y, a1, a2);
    
    double dist2 = calculateDistance(x, y, b1, b2);
    double dist3 = calculateDistance(0, 0, a1, a2);
    double dist4 = calculateDistance(0, 0, b1, b2);
    double dist5 = calculateDistance(a1, a2, b1, b2);

    double fgf = max(min(dist1, dist2), min(dist3, dist4));
    if (min(dist1, dist2) == dist1 && min(dist3, dist4) == dist3) {
        // Do something if necessary

        ans+=cnt*576*mf;
    } else if (min(dist1, dist2) == dist2 && min(dist3, dist4) == dist4) {
        // Do something if necessary
          ans+=cnt*N*mf;
    } else {
        if (dist5 > 2 * fgf) {
            fgf = dist5 / 2;
        }
    }

    cout << setprecision(11);
     
    cout << (fgf)<< endl;

    
  }

  return 0;
}

