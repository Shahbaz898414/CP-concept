#include <bits/stdc++.h>
using namespace std;

#define ll long long

// #ifndef ONLINE_JUDGE
// #include "algo/debug.h"
// #else
// #define dbg(...) ;
// #define debug(...) ;
// #define crndl ;
// #endif

const long long N = (long long)(1e5 + 5);
const long long inf = (long long)(1e18);

vector<ll> adj[N];
bool vis[N];
ll d[N];
ll maxd = 0;

void dfs(vector<vector<ll>> &al, vector<ll> &ac, ll a, ll depth)
{
  ac[depth]++;

  // cout<<depth<<" ";

  for (auto u : al[a])
  {
    // cout<<depth<<endl;
    dfs(al, ac, u, depth + 1);
    cout<<depth<<endl;
  }
}



void solve() {

  ll n;
  cin >> n;

  vector<vector<ll>> al(n + 1);
  vector<ll> ac(n + 1);

  for (ll i = 2; i <= n; i++)
  {
    /* code */
    ll a;
    cin >> a;

    al[a].push_back(i);
  }

  dfs(al, ac, 1, 1);

  cout<<endl<<"end"<<endl;

  int ans = 0;
  for (int i = 0; i <= n; i++)
  {
    /* code */
    cout<<ac[i]<<" ";
    ans += (ac[i] % 2);
  }

  cout<<endl;

  cout << ans << endl;
}

int32_t main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // #ifndef ONLINE_JUDGE
  //   freopen("io/input.txt", "r", stdin);
  //   freopen("io/output.txt", "w", stdout);
  //   freopen("io/error.txt", "w", stderr);
  // #endif

  int t = 1;
  // cin >> t;

  for (int _t = 1; _t <= t; _t++)
  {
    // debug(Testcase, _t);
    solve();
    // crndl;
  }

  return 0;
}

/*


Let's understand the problem:

Arcady has a peculiar apple tree. The tree has n inflorescences, numbered from 1 to n. The inflorescence number 1 is at the base of the tree, and any other inflorescence with number i (i > 1) is situated at the top of a branch, which bottom is pi-th inflorescence, and pi < i. When the tree starts fruiting, one apple appears in each inflorescence. Apples start rolling down along branches towards the base of the tree. Each second, all apples, except the ones in the first inflorescence, simultaneously roll down one branch closer to the tree base. Apples that end up in the first inflorescence are gathered by Arcady. The apples annihilate if there are more than one in the same inflorescence.

The task is to count the number of apples Arcady will be able to collect from the first inflorescence during one harvest.

Now, let's dry run the provided testcase:


      1
    / | \
   2  3  4
  /|  |  | \
 5 6  7  8  9
  |      |
 10     11
 |      /
 12    13
 |    / \
 14  15  16
 |  /
 17
 |
 18


       1
     /| \
    2 3  4
   /| |   \
  5 6 7    8
   |       |
  9       10
          |
         11
        / |
       12 13
         / \
        14 15
        / \
       16 17
          |
         18


        1
       | \
       2 3
         \
          4
           \
            8
             \
              9
              |
             10
             |
            11
           / \
         12   13
          \    \
          14   15
          / \
         16 17
            |
           18


       1
      / \
     2   3
          \
           4
             \
              9
              |
             10
             |
            11
           / \
         12   13
            / \
           14 15
              \
               18





 1 0
 2 0
 3 0


*/