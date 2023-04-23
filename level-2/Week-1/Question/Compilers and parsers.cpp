#include<bits/stdc++.h>
#define ll long long
using namespace std;



int main() {
  
  int t;cin>>t;

  while(t--) {
    string s;cin>>s;
    int len=s.size();

    int cur=0,pre=0;

    for(int i=0;i<len;i++) {
      if(s[i]=='<'){
        cur++;
      }else {
        cur--;
      }


      if(cur<0){
        break;
      }

      if(cur==0){
        pre=i+1;
      }
    }

    cout<<pre<<endl;
  }


  return 0;
}