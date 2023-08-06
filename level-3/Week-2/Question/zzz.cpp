#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int M = 1e9 + 7;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // int t;
    // cin >> t;
    // while (t--)
    // {
        ll n;
        cin >> n;
        vector<string> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        


      for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            int cnt=0;
            if(j>0 and a[i][j-1]=='o') cnt++;
            if(j<n-1 and v[i][j+1]=='o')c++;
         if(i>0 and v[i-1][j]=='o')c++;
         if(i<n-1 and v[i+1][j]=='o')c++;   
        }
      }
      
        
    // }
    return 0;
}
