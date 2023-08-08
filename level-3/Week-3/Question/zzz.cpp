#include <bits/stdc++.h>
using namespace std;
#define ll long long



bool vs(int  v,int s){
  if(v>s){
    return v;

  }else{
    return s;
  }
}
int main( ){

  ll t;
  cin >> t;
  while (t--)
  {
   ll  n;cin>>n;

   ll s;cin>>s;

   ll x=ceil((double)n/2);

   n-=(x-1);

   cout<<s/n<<endl;
    



  }

  return 0;
}
