#include <bits/stdc++.h>
#define ll long long
using namespace std;



int main()
{
  ll t;
  cin >> t;

  while (t--)
  {
    ll n;
    cin >> n;

    
   ll a=1,b=1,c=1;

   for (int i = 2; i*i <=n; i++) {
    if(n%i==0){
      a=i;
      break;
    }
   }

   n=n/a;

   for (int i = 2; i*i <=n; i++)
   {
    /* code */
    if(n%i==0){
      if(a!=i){
        b=i;
        break;
      }
    }
   }


   c=n/b;

   if(a!=b and b!=c and c!=1 and b!=1 and a!=1 ) {
    cout<<"YES"<<endl;
    cout<<a<<" "<<b<<" "<<c<<endl;

    // cout<<a*b*c<<endl;
   }else {
    cout<<"NO"<<endl;
   }
      
    
  }
}