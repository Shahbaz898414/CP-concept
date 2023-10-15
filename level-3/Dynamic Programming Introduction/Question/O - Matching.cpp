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


/*



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
     
      for (int mask = 0; mask < (1<<n)-1; mask++)
      {
       

        int a=__builtin_popcount(mask);
        for (ll b = 0; b < n; b++)
        {
         
          if(can[a][b] and !(mask & (1<<b))){
            int m2=mask^(1<<b);

            add_self(dp[m2],dp[mask]);
          }
        }
        
      }
      
    // }

    cout<<dp[(1<<n)-1]<<endl;



*/




    ll n;cin>>n;

    vector<vector<ll>>  can(n,vector<ll>(n));

    for (ll i = 0; i <n; i++) {
      for (ll j = 0; j <n; j++) {
        
        cin>>can[i][j];
      }
      
    }


    vector<vector<int>>  dp(n,vector<int>((1<<n),-1));

    function<int(int,int)> solve = [&] (int i,int mask){

      if(mask+1==(1<<n)) return 1;


      if(i>=n)  return 0;
       

       if(dp[i][mask]!=-1)  return dp[i][mask];


       dp[i][mask]=0;


       for (int j = 0; j < n; j++) {


        if((mask&(1<<j))>0)continue;


        if(can[i][j]==1)  {


          (dp[i][mask]+=solve(i+1,mask|(1<<j)))%=mod;


        }


       }


       return dp[i][mask];
       

    };

    cout<<solve(0,0)<<endl;  
    
    
  }

  return 0;
}




















