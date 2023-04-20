#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
    ll n; cin>>n;
    string s;cin>>s;

    int cnt1=0,cnt2=0,mx1=0,mx2=0;

    for(int i=0;i<n;i++) {
      if(s[i]=='A') {
        cnt1++;
        // mx1=max(mx1,cnt2);
        // cnt2=0;
      }else {
        cnt2++;
        // mx2=max(mx2,cnt1);
        // cnt1=0;
      }

      // cout<<mx1<< " "<<mx2<<endl;
    }

    // cout<<endl;

    // cout<<mx1<<" "<<mx2<<endl;

    // if(mx2==mx1){
    //   cout<<"Friendship"<<endl;
    // }else if(mx2>mx1) {
    //   cout<<"Anton"<<endl;
    // }else {
    //   cout<<"Danik"<<endl;
    // }


    if(cnt2==cnt1){
      cout<<"Friendship"<<endl;
    }else if(cnt1>cnt2) {
      cout<<"Anton"<<endl;
    }else {
      cout<<"Danik"<<endl;
    }

    
  


  return 0;
}