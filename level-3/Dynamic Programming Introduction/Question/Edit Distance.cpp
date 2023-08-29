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

const ll N=1e5;
ll fact[N+1];

void precomp() {
  fact[0]=1;

  for (ll i = 0; i <=N; i++)
  {
    
    fact[i]=(fact[i]*i)%mod;
  }
  
}


ll power(ll base,ll x){
  if(x<0){
    return 0;
  }

  ll ans=1;
  while(x){
    if(x%2==0){
      base=(base*base)%mod;
      x=x/2;
    }else {
      ans=(ans*base)%mod;
      x--;
    }
  }

  return ans;
}


ll ncr(ll n,ll r ){
  if(r>n)  return 0;

  ll numo=fact[n];
  ll demo=(fact[r]*fact[n-r])%mod;
  ll ans=(numo*power(demo,mod-2))%mod;

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




signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 

  string s1,s2;cin>>s1>>s2;
   //taking input

    int len_s1 = s1.size();
    int len_s2 = s2.size();
    int dp[len_s1+1][len_s2+1];

    for(int i=0;i<=len_s1;i++)
    {
        for(int j=0;j<=len_s2;j++)
        {
            if(i == 0)
              dp[i][j] = j; 
              // when s1 is empty, we just have to copy j elements of string s2

            else if(j == 0)
              dp[i][j] = i; 
              //  when s2 is empty, we just have to remove i elements present in s1.

            else if(s1[i-1] == s2[j-1])
              dp[i][j] = dp[i-1][j-1]; 
              // if the last element is same in both s1 & s2, just copy the previous dp value. No more changes needed

            else
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
                //case1 = dp[i][j-1] = when we insert an element in s1. 
                // After insertion, we calculate the dp[for the rest of s1(i)][for the rest of s2 other than the last element which is inserted in s1(j-1)].

                // case2 = dp[i-1][j] = when we remove element from s1. We calculate dp[rest of s1(i-1)][rest of s2(j)]

                // case3 = dp[i-1][j-1] = when element of s1 is replaced. 

                // calculate min of the three. 1 is added as each case counts to 1 operation
            
        }
    }

    for (int i = 0; i <len_s1; i++)
    {
      /* code */
      for (int j = 0; j < len_s2; j++)
      {
        /* code */

        cout<<dp[i][j]<<" ";
      }
      cout<<endl;
      
    }
    

    cout<<dp[len_s1][len_s2]<<endl;

  return 0;
}


