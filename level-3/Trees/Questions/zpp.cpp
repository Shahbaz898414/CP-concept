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

const long long inf = 1e18;
const int MOD = 1e9 + 7;
const int MAX = 1e6;

int largestSubmatrix(vector<vector<int>> &matrix)
{
  int m = matrix.size();
  int n = matrix[0].size();
  for (int i = 1; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (matrix[i][j] == 1)
      {
        matrix[i][j] = matrix[i - 1][j] + 1;
      }
    }
  }



  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) { 
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  

  int ans = 0;
  for (auto itr : matrix)
  {
    sort(itr.begin(), itr.end());

    for (int k = n - 1, w = 1; k >= 0 && itr[k] > 0; k--, w++)
    {

      
      int area = itr[k] * w;

      ans = max(ans, area);


    }
  }
  return ans;
}

int32_t main()
{

  ll n, m;
  cin >> n >> m;

  vector<vector<int>> arr(n, vector<int>(m));

  for (ll i = 0; i < n; i++)
  {
    /* code */
    for (ll j = 0; j < m; j++)
    {
      /* code */
      cin >> arr[i][j];
    }
  }

  cout << largestSubmatrix(arr);

  return 0;
}

/*



Today was my 53th day out of the 100 days  hard challenge.
So today, I solved 5 problems .


1. A. Line Trip (https://codeforces.com/problemset/problem/1901/A).


2. A. Cover in Water (https://codeforces.com/contest/1900/problem/A).


3. B. Laura and Operations (https://codeforces.com/contest/1900/problem/B)


4. C. Anji's Binary Tree (https://codeforces.com/contest/1900/problem/C).


5. B. Chip and Ribbon (https://codeforces.com/contest/1901/problem/B).


#100dayschallenge #challenge #consistency #Cp #lessons  #learning #setmentTree


*/

/*


class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]!=0)matrix[i][j]+=matrix[i-1][j];
            }
        }

        int maxarea=INT_MIN;


        for(int i=0; i<n; i++){
            sort(matrix[i].begin(), matrix[i].end(),greater<int>());
            int temp=INT_MAX;
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0)continue;
                temp=min(temp,matrix[i][j]);
                int area=(j+1)*temp;
                maxarea=max(maxarea,area);
            }
        }
        if(maxarea==INT_MIN)return 0;
        return maxarea;
    }
};


*/

/*

 int m=matrix.size();
        int n=matrix[0].size();
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==1)
                {
                    matrix[i][j]=matrix[i-1][j]+1;
                }
            }
        }
        int ans=0;
        for(auto itr:matrix)
        {
            sort(itr.begin(),itr.end());

            for(int k=n-1,w=1;k>=0 && itr[k]>0;k--,w++)
            {
                int area=itr[k]*w;
                ans=max(ans,area);
            }
        }
        return ans;


*/