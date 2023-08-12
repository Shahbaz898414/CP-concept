#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main()
{


  // cout<<1<<endl;
  ll t;
  cin >> t;

  map<ll, vector<ll>> mp;

  for (ll i = 1; i <= 100003; i++)
  {
    /* code */
    for (ll j = 1; j <= sqrt(i); j++)
    {

      if (i % j == 0)
      {
        if (i / j == j)
        {
          mp[i].push_back(j);
        }
        else
        {
          mp[i].push_back(j);
          mp[j].push_back(i / j);
        }
      }

      /* code */
    }
  }


  // cout<<2<<endl;

  // ll g=0;
  while (t--)
  {
    // cout<<g++<<endl;
    ll n;
    cin >> n;
  cout<<n<<endl;
    vector<ll> vec(n+1);

    for (ll i = 1; i <=n; i++)
    {
      cin >> vec[i];
      cout<<vec[i]<<" ";
    }

    cout<<endl;

    ll ans[n+1];
    for (ll i = 1; i <=n; i++)
    {
      /* code */
      for(auto x:mp[i]){
        if(vec[x]<vec[i]){
          ans[i]=max(ans[i],ans[x]+1);
        }
      }  
    }


    // ll fl=INT_MIN;

    // for (ll i =1; i <=n; i++)
    // {
    //   /* code */
    //   if(fl<ans[i]){
    //     fl=ans[i];
    //   }
    // }
    
    // cout<<fl<<endl;
    
  }

  return 0;
}
