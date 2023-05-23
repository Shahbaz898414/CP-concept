#include <bits/stdc++.h>
#define int long long


const int mod =1e9+7;
using namespace std;



int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    int n = s.size();
    vector<int> pfx(n);
    vector<int> sfx(n);
    long long p = 1;
    for(int i=0;i<n;++i){
        pfx[i] = (p*1LL*(s[i]-'a'+1))%mod;
        if(i != 0){
            pfx[i] += pfx[i-1];
            pfx[i] %= mod;
        }
        p *= 31;
        p %= mod;
    }
    p = 31;
    for(int i=n-1;i>=0;--i){
        sfx[i] = (s[i]-'a'+1);
        if(i != n-1){
            sfx[i] += ((p*1LL*sfx[i+1])%mod);
            sfx[i] %= mod;
        }
    }
    for(int i=0;i+1<n;++i){
        //cout<<pfx[i]<<" "<<sfx[n-i-1]<<"\n";
        if(pfx[i] == sfx[n-i-1]){
            cout<<(i+1)<<" ";
        }
    }
    
   
}