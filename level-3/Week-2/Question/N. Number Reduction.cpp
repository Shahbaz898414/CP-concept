#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{

    int t;cin>>t;

    while(t--) {
      string s;cin>>s;

      ll k;cin>>k;

      int st=0;

      for (int i = 0; i <=k; i++)
      {
        /* code */
        if(s[i]!='0' and s[i]<s[st]){
          st=i;
        }
      }

      cout<<st<<endl;

      k-=st;

      string ans;

      ans.push_back(s[st]);

      int cnt=0;

      for (int i =st+1; i <s.size(); i++)
      {
        /* code */
        while(k>0 and ans.size()>1 and ans.back()>s[i]){
          ans.pop_back();

          k--;
        }

        ans+=s[i];

        // cout<<ans<<" "<<cnt++<<endl;
      }

      while(k--) ans.pop_back();
      

      cout<<ans<<endl;

    }

    return 0;
}

