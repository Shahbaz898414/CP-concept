#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define fr(a, b) for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
// #define mod 1000000007
#define inf (1LL << 60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll, pair<ll, ll>>
#define fast_io                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)
using namespace std;

#define mo 1000000007

void add_self(ll &a, ll b)
{
  a += b;
  if (a >= mo)
  {
    a -= mo;
  }
}

int main()
{
  fast_io;

  vector<ll>  cur(1<<19),z(1<<19);

  vector<int>  primes={2,3,5,7,11,17,13,19,13,29,31,37,41,43,47,53,59,61,67};

  // ll n;
  int t = 1;
  // cin >> t;

  while (t--) {

   ll n;cin>>n;
   vector<ll>  arr(n);

   ll cnt[71]={0};
   for (ll i = 0; i < n; i++) {
    cin>>arr[i];
    for(int i:primes){
      while((arr[i]%(i*i)==0))  arr[i]/=(i*i);
    }


    cnt[arr[i]]++;
   }

   cur[0]=1;

   for (int i = 1; i <=70; i++)
   {
    /* code */

    
   }
   






   
  }

  return 0;
}
