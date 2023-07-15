#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long long int

void solve() {
    ll n, k; cin >> n ;

    vector<ll> arr(n);
    ll g = 0; ll rem = 0, store = 0;

    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(),arr.end());

    double z=0;

    // for (ll i = n-2; i >=0; i--)
    // {
    //     /* code */
    // }
    

    for (ll i = 0; i < n; i++) {
        if(i==0){
            z=arr[n-1];
            
        }else {
            z=(z+arr[n-1-i])/2;
        }
    }
    
    cout<<fixed<<setprecision(8)<<z<<endl;
    
}


int main()
{

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
