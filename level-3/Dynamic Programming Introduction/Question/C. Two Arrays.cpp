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

ll m = 998244353;

long long erfd(long long a, long long b)
{
  if (b == 0)
    return 1;
  long long ans = erfd(a, b / 2);
  if (b % 2)
    return (ans % m * ans % m * a) % m;
  else
    return ans % m * ans % m;
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

signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // ll t = 1;
  // // cin>>t;
  // while (t--)
  // {

    ll dp[25][1005];

    ll n, m, ans;
    cin >> n >> m;

    for (ll i = 1; i <= m + m; i++)
    {
      /* code */
      dp[i][1] = 1;
      for (int j = 2; j <= n; j++)
        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
      
    }



    for (int i = 1; i <= n; i++)
       ans = (ans + dp[m + m][i]) % mod;


    cout << ans << endl;
  // }

  return 0;
}

/*


#include<iostream>
using namespace std;
int main()
{
  int m,n;
  cin>>m>>n;
  int k=2*n+1;
  int a[k*2][m + 5];
  for(int i=0;i<m;i++)a[0][i]=1;
  for(int i=1;i<k;i++)
  {
    a[i][0]=1;
    for(int j=1;j<m;j++)
    a[i][j]=(a[i-1][j]+a[i][j-1])%1000000007;
  }
  cout<<a[k-1][m-1];
  return 0;
}







#include<cstdio>
#include<iostream>
using namespace std;
const int skc=1e9+7;
int n,m,i,j,k,ans,f[2001][2001];
int main(){
  scanf("%d%d",&n,&m);swap(n,m);n<<=1;
  f[0][1]=1;
  for(i=1;i<=n;i++)for(j=1;j<=m;j++)for(k=1;k<=j;k++)f[i][j]=(f[i][j]+f[i-1][k])%skc;
  for(i=1;i<=m;i++)ans=(ans+f[n][i])%skc;
  printf("%d\n",ans);
}









#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,ans,dp[25][1005];
signed main()
{
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m+m;i++){
    dp[i][1]=1;
    for(int j=2;j<=n;j++){
      dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
    }
  }
  for(int i=1;i<=n;i++)ans=(ans+dp[m+m][i])%mod;
  printf("%d",ans);
  return 0;
}




*/