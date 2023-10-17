
#include<bits/stdc++.h>
using namespace std;

using ll = long long;



int main() {
  ll n,m;cin>>n>>m;

  set<int>  st;

  for (int i = 0; i < n; i++ ){
    st.insert(i);
  }

  vector<int>  ans(n,0);


  for (int i = 0; i < m; i++)
  {
    /* code */
    int l,r,x;cin>>l>>r>>x;

    l--;r--;x--;

    while(st.lower_bound(l)!=st.end() and *st.lower_bound(l)<=r){
      ans[*st.lower_bound(l)]=x+1;

      st.erase(st.lower_bound(l));
    }

    ans[x]=0;

    st.insert(x);
  }
  
  cout<<ans<<endl;
}