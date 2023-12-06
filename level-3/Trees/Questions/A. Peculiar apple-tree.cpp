#include <bits/stdc++.h>
using namespace std;

#define ll long long


#ifndef ONLINE_JUDGE
// #include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif

const long long N=(long long)(1e5+5);
const long long inf=(long long)(1e18);


vector<ll> adj[N];
bool vis[N];
ll d[N];
ll maxd=0;



void dfs(ll nd,ll cur){
	vis[nd]=true;
	d[cur]++;
	maxd=max(maxd,cur);
	for(auto it:adj[nd]){
		if(!vis[it]){
			dfs(it,cur+1);
		}
	}
	
}
void solve(int tc)
{
	ll n;
	cin>>n;
	ll a[n+1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		adj[a[i]].push_back(i);
		adj[i].push_back(a[i]);
	}
	ll cur=0;
	dfs(1,cur);
	ll ans=0;
	for(ll i=0;i<=maxd;i++){
		ans+=(d[i]%2);
	}
	cout<<ans;
	
	//Nodes at same depth will contribute either 0 or 1 depending on parity
	//Editorial approach
	
}


int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("io/input.txt", "r", stdin);
    freopen("io/output.txt", "w", stdout);
    freopen("io/error.txt", "w", stderr);
    #endif
	
	int t = 1;
	cin >> t;
	
	for(int _t = 1; _t <= t; _t++) {
		// debug(Testcase, _t);
		solve(t);
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






*/