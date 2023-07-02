#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n,x,m;cin>>n>>x>>m; ll a=x,b=x;

    for (int i = 1; i <=m; i++) {
      ll c,d;cin>>c>>d;

      if(b>=c and a<=d){
        b=max(b,d);
        a=min(a,c);
      }


    }


    cout<<b-a+1<<endl;
    
  }
}