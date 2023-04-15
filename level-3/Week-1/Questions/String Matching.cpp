#include <bits/stdc++.h>
using namespace std;

#define ll long long


long long getHas(string s){
  long long h=0;

  for(auto c:s)  h=( h*31+( c-'a'+1 ) )%MOD;

  return h;

}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1,s2; cin >> s1>>s2;

    int a= s1.length();
    int b=s2.length();

    if(b>a){
      cout<<0<<endl;
      return 0;
    }



   
    return 0;
}