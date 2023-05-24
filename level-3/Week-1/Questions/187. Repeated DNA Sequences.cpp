#include <bits/stdc++.h>
#define ll long long
using namespace std;



int32_t main() {

    string s;cin>>s;

    ll len=s.size();

    vector<string> v;
      map<string,int> mp;
    for (ll i = 0; i < len-10; i++) {
      string h=s.substr(i,10);
      mp[h]++;
    }

    for(auto it:mp){
      if(it.seocnd>1){
        v.push_back(it.first);
      }
    }


    
    
    
}

/*
string s;
    cin>>s;
    int n=s.size(),t=0;
    for(int i=0; i<n; i++)
    {
        int x=s.find("bear",i);
        if(x!=-1)
            t+=n-x-4+1;
    }
    cout<<t;
*/