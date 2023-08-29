#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
   ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t;cin>>t;
 
    ll x,y;
 
    vector<pair<ll,bool>> v;
 
    while(t-->0) {
      ll n,m;cin>>x>>y;
 
      v.push_back({x,true});
      v.push_back({y,false});
      
    }
 
    sort(v.begin(),v.end());

    for(auto it:v){
        cout<<it.first<<" "<<it.second<<endl;
    }
 
    ll ans=0,res=0;
 
    for (int i = 0; i <v.size(); i++) {
      
      if(v[i].second==true){
        ans++;
 
        res=max(res,ans);
      }else {
        ans--;
      }
    }
 
    cout<<res<<endl;
    
 
    return 0;
}