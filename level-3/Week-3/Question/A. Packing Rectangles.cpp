#include <bits/stdc++.h>
using namespace std;
#define ll long long

 ll w,h,n;

bool good(ll i)
{
  return (i/w)*(i/h)>=n;
}

int main()
{
  // ll t;
  // cin >> t;

  // while (t--)
  // {
  cin>>w>>h>>n;

   ll l=0;
   ll r=1;
   while(!good(r)) r*=2;



   while(r>l+1){
    ll m=(l+r)/2;
    if(good(m)){
      r=m;
    }else{
      l=m;
    }
   }

   cout<<r<<endl;

  // }
  return 0;
}


