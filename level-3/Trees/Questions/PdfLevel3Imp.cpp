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

vector<bool> is_prime(10001, 1);
vector<int> primes;

void seive()
{
  is_prime[0] = 0;
  is_prime[1] = 0;
  for (int i = 2; i < 10001; i++)
  {
    if (is_prime[i])
    {
      primes.push_back(i);
      for (int j = i + i; j < 10001; j += i)
      {
        is_prime[j] = 0;
      }
    }
  }
}


/*

find out the biggest kth parent of X for which it is not equal to the parent of Y
return the 1st parent of Z


*/






// dfs(0, edge, -1, parents, maxparent);

void dfs(int curr, vector<vector<int>> &edgs, int currParent, vector<vector<int>> &parents,vector<int>&levels)
{
    parents[curr][0] = currParent;

    if(currParent!=-1){
      levels[curr]=levels[currParent]+1;
    }

    for (auto child : edgs[curr])
    {
        if (child != currParent)
        {
            dfs(child, edgs, curr, parents,levels);
        }
    }
}

int kthParent(int x, int k, vector<vector<int>> &parents)
{
    int maxParent = parents[0].size();

    for (int i = 0; i < maxParent; i++)
    {
        if (((k >> i) & 1))
        {
            if (x != -1)
                x = parents[x][i];
        }
    }

    return x;
}





int lca(int x,int y,vector<vector<int>> &parent,vector<int>&level) {

    if(x==y)  return x;

    if(level[x]<level[y]){
      swap(x,y);


    }

    int diffLevel=level[x]-level[y];

    x=kthParent(x,diffLevel,parent);


  int mxlog = parent[0].size();


  for (int i = mxlog-1; i >=0; i--) {


    int parentofX=parent[x][i];
    int parentofY=parent[y][i];


    if(parentofX!=parentofY){


      x=parentofX;
      y=parentofY;


    }


  }


 return parent[x][0];
 

}


int32_t main()
{

  ll t=1;
  // cin >> t;
  // seive();
  while (t--)
  {
    int n, q;
    cin >> n >> q;

   int root = 0;


    int maxparent = log2(n) + 1;


    // cout<<n<<" "<<maxparent<<endl;


    vector<vector<int>> parents(n, vector<int>(maxparent, -1));


    vector<int>  levels(n);

    vector<vector<int>> edge(n, vector<int>());


    for (int i = 1; i < n; i++)  {
        // int a,b;cin>>a>>b;
        // edge[a-1].push_back(b-1);
        // edge[b-1].push_back(a-1);

        int a;cin>>a;


        edge[a-1].push_back(i);

    }

 
    dfs(root, edge, -1, parents,levels);


    // debug(parents);


    for (int j = 1; j < maxparent; j++)
    {
        for (int i = 0; i < n; i++)
        {
            int intermediate = parents[i][j - 1];
            if (intermediate != -1)
            {
                parents[i][j] = parents[intermediate][j - 1];
            }
        }
    }


    // debug(parents);


    vector<int> inTime(n),outTime(n);
    int globalTime=0;

    // dfs_in_out(root,edge,-1,inTime,outTime,globalTime);

    while(q--) {


      int a,b;cin>>a>>b; a--;b--;


      cout<<lca(a,b,parents,levels)+1<<endl;


    }

    
    
  }
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