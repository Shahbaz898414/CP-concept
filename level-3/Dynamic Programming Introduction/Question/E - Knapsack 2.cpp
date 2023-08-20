/*

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

  // int t;
  // cin >> t;
  // while (t--)
  // {

  ll n, w;
  cin >> n >> w;

  vector<ll> v(n);

  vector<ll> wt(n);

  for (ll i = 0; i < n; i++)
  {
    cin >> wt[i] >> v[i];
  }

  vector<vector<int>> dp(n, vector<int>(w + 1, 0));

  for (ll i = wt[0]; i <= w; i++)
  {
    dp[0][i] = v[0];
  }

  for (ll i = 1; i < n; i++)
  {
    for (ll j = 0; j <= w; j++)
    {
      int notTaken = 0 + dp[i - 1][j];

      int taken = INT_MIN;
      if (wt[i] <= j)
      {
        taken = v[i] + dp[i - 1][j - wt[i]];
      }

      dp[i][j] = max(notTaken, taken);
    }
  }

  cout << dp[n - 1][w];

  // }
  return 0;
}


*/





#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

#define fast ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long 
#define pb push_back
#define endl '\n'

using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update>pbds;

const int mod=1e9+7;

int binExp( int x, int y){
	// x%=mod;
	// y%=mod;
	int res=1;
	while(y){
		if(y&1)
			res=(res*x);
		y>>=1;
		x=(x*x);
	}
	return res;
}
int modAdd(int x,int y){
	x%=mod;
	y%=mod;
	return (x+y)%mod;
}
int modSub(int x,int y){
	x%=mod;
	y%=mod;
	return (x-y+mod)%mod;
}
int modMul(int x,int y){
	x%=mod;
	y%=mod;
	return (x*y)%mod;
}
int modDiv(int x,int y){
	y=binExp(y,mod-2);
	int z=modMul(x,y);
	return z;
}
bool cmp(pair<int,int>&a,pair<int,int>&b){
	// if(a.first==b.first)
	// 	return a.second<b.second;
	return a.second<b.second;
}
int factorial(int n){
	int fact=1;
	for(int i=1;i<=n;i++){
		fact*=i;
	}
	return fact;
}
int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b,a%b);
}
int helper(int i,int n,int w,vector<pair<int,int>>&v,vector<vector<int>>&dp){
	if(i==n){
		return 0;
	}
	if(dp[i][w]!=-1){
		return dp[i][w];
	}
	int nt=0,t=0;
	nt=helper(i+1,n,w,v,dp);
	if(v[i].first<=w){
		t=v[i].second+helper(i+1,n,w-v[i].first,v,dp);
	}
	return dp[i][w]=max(nt,t);
}
signed main(){
// #ifndef ONLINE_JUDGE
// 	//file input.txt is opened in reading mode 
//     freopen("inputf.in","r",stdin);
//     //file output.txt is opened in writing mode 
//     freopen("outputf.out","w",stdout); 
// #endif
/* Two type of operations mainly perform in ordered set:-
	1)- find_by_order(x) finding the element present at the xth index in the set(it return a iterator)
	2)- order_of_key(x) finding number of element smaller than x in the set

*/ 
	fast;
	int n,w;
	cin>>n>>w;
	vector<pair<int,int>>v;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v.pb({x,y});
	}
	vector<vector<int>>dp(n,vector<int>(w+1,-1));
	cout<<helper(0,n,w,v,dp);
	return 0;
}
