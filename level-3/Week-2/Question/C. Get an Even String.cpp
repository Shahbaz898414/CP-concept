#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define lld long long int

void solve()
{
    string s;
    cin >> s ;

    ll n = s.length();


    vector<bool>  has(25,false);

    int cnt=0;

    for (int i = 0; i < n; i++)
    {
      /* code */
      if(has[s[i]-'a']){
        cnt+=2;

        has.assign(26,false);
      }else has[s[i]-'a']=true;
    }

    
    cout<<n-cnt<<endl;
  
}

int main()
{

    int t;cin>>t;
    while(t--) {
        solve();
    }

  

    return 0;
}


