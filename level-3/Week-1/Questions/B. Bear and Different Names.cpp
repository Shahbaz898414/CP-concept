




#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

long long getHas(string s){
  long long h=0;

  for(auto c:s)  h=( h*31+( c-'a'+1 ) )%MOD;

  return h;

}

int main() {
  cout<<(getHas("ab") == getHas("ab"));
  return 0;
}





