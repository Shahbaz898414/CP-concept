#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll query(ll i)
{
  cout << "? " << i + 1 << endl;
  ll x;
  cin >> x;
  return x - 1;
}

int main()
{
  // ll t;
  // cin >> t;

  // while (t--)
  // {
    ll n;
    cin >> n;
    ll p[n];
    ll l=0;
    ll r=n+1;

    ll a,b;

    while(l+2<r){
      int mid=(l+r)/2;
      cout<<"? "<<mid<<endl;
      cin>>a;
      cout<<"? "<<mid+1<<endl;
      cin>>b;

      if(a>b)  l=mid;
      else r=mid+1;
    }

    cout<<"! "<<l+1<<endl;

  // }
  return 0;
}

/*

for(int i=0;i<n;i++) {
  if(a[i]<0){
    cnt++;
  }
}



*/
