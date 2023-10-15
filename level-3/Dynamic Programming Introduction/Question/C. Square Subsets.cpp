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



// #define mo 1000000007

// void add_self(ll &a, ll b)
// {
//   a += b;
//   if (a >= mo)
//   {
//     a -= mo;
//   }
// }




int main() {


  fast_io;


  vector<ll>  cur(1<<19),z(1<<19);


  vector<int> primes={2,3,5,7,11,17,13,19,23,29,31,37,41,43,47,53,59,61,67};


  // ll n;
  // int t = 1;
  // cin >> t;


  // while (t--) {

   ll n;cin>>n;
  //  vector<ll>  arr(n);

   ll cnt[71]={0};

   for (ll i = 0; i < n; i++) {


    ll x;cin>>x;


    for(int i:primes){
      while((x%(i*i)==0))  x/=(i*i),cout<<x<<" ";

    }
 


    cnt[x]++;

   }

   cout<<endl;
   
   for (int i = 0; i <=71; i++)
   {
    /* code */
    cout<<cnt[i]<< " ";

   }
   cout<<endl;
   


   cur[0]=1;


   for (int i = 1; i <=70; i++)
   {


    if(cnt[i]) {


      ll int mo = 1;


      for (int j = 0; j < cnt[i]-1; j++) {  


        mo = 2 * mo % mod;


      }



      for (int j = 0; j < z.size(); j++) {


        z[j]=0;


      }


      int tmp=0;


      for (int j = 0; j < primes.size(); j++)
      {


        if((i%primes[j]) == 0)  tmp ^= (1<<j);


      }


      for (int j = 0; j < cur.size(); j++)
      {


        z[j^tmp] +=mo*cur[j];
        z[j^tmp] %=mod;
        z[j] +=mo*cur[j];
        z[j] %=mod;


      }


      swap(z,cur);      


    }


   }


   cur[0]= (cur[0] + mod-1) % mod;


   cout<<cur[0]<<endl;
   
   
  // }

  return 0;
}


