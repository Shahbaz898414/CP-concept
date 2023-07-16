#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define lld long long int
#define fo(i, n)          for (int i = 0; i < n; i++)


int main() {

    int t;cin>>t;
    while(t--) {
      ll n;cin>>n;
      map<char,int> mp1,mp2;

      char c='a';

      mp1[c]++;
      mp2[c]++;

      int k1=0,k2=0;

      while(n--) {
        int n,k;cin>>n>>k;

        string s;cin>>s;

        if(n==1){
          for (ll i = 0; i < s.size(); i++)
          {
            
            mp1[s[i]]+=k;
            k1+=k;
          }
          
        }else {
          for(ll i = 0; i < s.size(); i++)
          {
            
            mp2[s[i]]+=k;
            k2+=k;
          }
        }

        if(mp2.size()>=2) cout<<"YES"<<endl;
        else if(mp1.size()==1 and mp2.size()==1 and k2>k1){
          cout<<"YES"<<endl;
        } else{
          cout<<"NO"<<endl;
        }


      }


    }

  

    return 0;
}


