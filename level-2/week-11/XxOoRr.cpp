#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long long int
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

string convert(lld n)
{
  string s = "";
  while (n > 0)
  {
    if (n % 2 == 1)
      s = "1" + s;
    else
      s = "0" + s;
    n /= 2;
  }
  return s;
}

lld convertBack(string s)
{
  lld n = 0, p = 1;
  for (lld i = s.length() - 1; i >= 0; i--)
  {
    n += ((s[i] - '0') * p);
    p *= 2;
  }
  return n;
}

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
  if (a.first != b.first)
    return (a.first < b.first);
  else
    return (a.second > b.second);
}

int32_t main()
{

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    ll n, k; cin >> n >> k;
    vector<ll> arr(n);

    for (ll i = 0; i < n; i++)
      cin >> arr[i];

     ll ans=0;
     for (ll i = 0; i < 32; i++) {
      ll cnt=0;
      for(int j=0;j<n;j++){
	      if(arr[j]&(1<<i)){
	        cnt++;
	      }
	    }
      if(cnt%k==0){
        ans+=cnt/k;
      }else {
        ans+=cnt/k;
        ans++;
      }
     }
      cout<<ans+1<<endl;
  }

  return 0;
}
