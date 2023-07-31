#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isSubstring(string s, string t) {
    int n = s.length();int m = t.length();
    
    for (int i = 0; i <= n - m; i++) {
        bool found = true;
        for (int j = 0; j < m; j++) {
            if (s[i + j] != t[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return true;
        }
    }
    return false;
}

bool isGoodString(string s,vector<string> & arr){
  int n=s.length();

  if(n>=47){
    return true;
  }

  for(string it:arr){
    if(isSubstring(s,it)){
      return  true;
    }
  }

  return false;
}

int32_t main()
{

  // int t;
  // cin >> t;

  // while (t--)
  // {
    ll k, n;
    cin >> k >> n;

    vector<string>  arr(k);

    // vector<string>  brr(n);

    for (ll i = 0; i < k; i++)
    {
      /* code */
      cin>>arr[i];
    }

    for (ll i = 0; i < n; i++)
    {
      string s;cin>>s;
      if(isGoodString(s,arr)){
        cout<<"Good"<<endl;
      }else{
        cout<<"Bad"<<endl;
      }
    }
    
    
  // }
    
}