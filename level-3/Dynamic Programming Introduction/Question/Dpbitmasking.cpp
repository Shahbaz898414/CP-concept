
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


void add(ll &subset,ll x){
  subset=(subset^(1<<(x-1)));
}

void remove (ll &subset, ll x) {

    subset=(subset^(1<<(x-1)));

}


void display (ll subset){
  for (ll i = 0; i <=9; i++)
  {
   
    if(subset&(1<<i)){
      cout<<i+1<<" ";
    }
  }
}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n;cin>>n;

  add(n,5);
  // add(n,5);
  add(n,4);
  add(n,6);
  remove(n,6);
  // remove(n,1);



  display(n);


  return 0;
}



