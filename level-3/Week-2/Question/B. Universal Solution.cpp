#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long long int



int main() {

    int t;
    cin>>t;
    while(t--) {
      string str;
      cin>>str;

      ll r=0,s=0,p=0;
      char ch;
      for (ll i = 0; i < str.size(); i++) {
        if(str[i]=='S') s++;
        else if(str[i]=='R') r++;
        else p++;
      }
      
    ll mx=max({p,r,s});

    if(mx==r){
      ch='P';
    }else if(mx==s){
      ch='R';
    }else {
      ch='S';
    }

    for (ll i = 0; i <str.size(); i++)
    {
      /* code */
      cout<<ch;
    }

    cout<<endl;
    
    

      // cout<<s<<" "<<r<<" "<<p<<endl;
      

    }

  

    return 0;
}


