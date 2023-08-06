


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
    ll ans=1;
    while(n%ans==0){
        ans*=3;
    }

    // cout<<ans<<endl;

    cout<<n/ans+1<<endl;
    // vector<string> a(n), b(n);
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];

 

    // }
    return 0;
}
