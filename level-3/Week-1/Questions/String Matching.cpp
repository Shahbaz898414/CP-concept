#include <bits/stdc++.h>
#define int long long

using namespace std;
 
const int mod =1e9+7;

long long get_hash(string s){
    int n=s.size();

    long long h=0;

    for (int i = 0; i <n; i++){
        h=(h*31+(s[i]-'a'+1))%mod;

        return h;
    }
}


vector<int>  rabin_karp(string s,string t){
    int n=s.size(),m=t.size();
    long long p=1;

    for (int i = 0; i < m-1; i++) {
        p=(p*31)%mod;
    }

    vector<int> pos;
    long long ht=get_hash(t);

    long long hs=get_hash(s.substr(0,m));

    if(hs==ht) {
        pos.push_back(0);
    }
    

    for (int l = 1,r=m; r <n; l++,r++) {
        int del=((s[l-1]-'a'+1)*p)%mod;
        int add =s[r]-'a'+1;
        hs=((hs-del+mod)*31+add)%mod;
        if(hs==ht) pos.push_back(l);
    }

    return pos;
    
}
 
int32_t main()
{
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
   string s,t;cin>>s>>t;

   vector<int> v=rabin_karp(s,t);
//    cout<<size(rabin_karp(s,t))<<endl;
    cout<<v.size()<<endl;
}

/*















*/

