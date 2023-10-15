#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define fr(a, b) for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL << 60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll, pair<ll, ll>>
#define fast_io                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)
using namespace std;

#define mod 1000000007



void add_self(ll& a,ll b) {
  a+=b;
  if(a>=mod){
    a-=mod;
   }
}


int main()
{
  fast_io;

  // ll n;
  int t=1;
  // cin >> t;

  while (t--)
  {

    ll n;cin>>n;

    vector<vector<ll>>  can(n,vector<ll>(n));

    for (ll i = 0; i <n; i++) {
      for (ll j = 0; j <n; j++) {
        
        cin>>can[i][j];
      }
      
    }


    vector<ll>  dp(1<<n);

    dp[0]=1;

    // for (int a = 0; a < n; a++)
    // {
      /* code */
      for (int mask = 0; mask < (1<<n)-1; mask++)
      {
        /* code */

        int a=__builtin_popcount(mask);
        for (ll b = 0; b < n; b++)
        {
          /* code */
          if(can[a][b] and !(mask & (1<<b))){
            int m2=mask^(1<<b);

            add_self(dp[m2],dp[mask]);
          }
        }
        
      }
      
    // }

    cout<<dp[(1<<n)-1]<<endl;
    
    
  }

  return 0;
}




















/*




const int MOD = 1e9 + 7;

int countValidPairings(vector<vector<int>>& compatibility) {
    int N = compatibility.size();
    vector<int> dp(1 << N, 0);
    dp[0] = 1;

    for (int mask = 1; mask < (1 << N); ++mask) {
        int menCount = __builtin_popcount(mask); // Count number of set bits (men paired in this mask)
        for (int i = 0; i < N; ++i) {
            if ((mask & (1 << i)) && compatibility[menCount - 1][i]) {
                dp[mask] = (dp[mask] + dp[mask ^ (1 << i)]) % MOD;
            }
        }
    }

    return dp[(1 << N) - 1];
}




*/











