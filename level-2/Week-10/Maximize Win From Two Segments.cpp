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



int maximizeWin(vector<int>& v, int k) {
    ll len=v.size();

    vector<int> ans(len);
    vector<int>  suf(len+1);

    for (int i = 0; i < len; i++)
    {
      /* code */
      auto lb=upper_bound(v.begin(),v.end(),v[i]+k);
      lb--;
      int g=(lb-v.begin())-i+1;
      ans[i]=len;
    }

    for (int i = len-1; i >=0; i--)
    {
      /* code */
      suf[i]=max(suf[i+1],ans[i]);

    }

    int realans=0;


    for (int i = 0; i <len; i++)
    {
      /* code */
      int temp=ans[i]+suf[i+ans[i]];

      realans=max(temp,realans);
    }
    
    
    return realans;


}




int32_t main() {
 
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // int t;
  // cin >> t;
  // while (t--)
  // {


  int n, m;
  cin >> n >>m;
  vector<int>  arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

 cout<< maximizeWin(arr,m);

 


  // cout<<n*(m)<<endl;

  // }

  

  return 0;
}





/*



class Solution {
public:
    vector<vector<int>>dp;
    int fn(int ind,vector<int>&arr,int segment,int k) 
    {
        if(segment==0)
            return 0;
        if(ind>=arr.size())
            return 0;
        if(dp[ind][segment]!=-1)
            return dp[ind][segment];
        
        int non_pick=fn(ind+1,arr,segment,k); 
        int target=lower_bound(arr.begin(),arr.end(),arr[ind]+k+1)-arr.begin();
        int pick=target-ind; 
        
        pick+=fn(target,arr,segment-1,k);
        
        return dp[ind][segment]= max(non_pick,pick);
        
        
    }
        
    int maximizeWin(vector<int>& arr, int k) {
        int n=arr.size();
        dp.resize(n,vector<int>(3,-1));
        
        return fn(0,arr,2,k);
        
        
    }
};


*/