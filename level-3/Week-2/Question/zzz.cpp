#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int M = 1e9 + 7;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n),b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (ll i = 0; i < n; i++)
        {
            /* code */
            cin>>b[i];
        }
        

        ll l=0,r=0;


        ll maxi = LLONG_MIN;

        for (ll i = 0; i < n; i++)
        {
            /* code */
            if(a[i]!=b[i] and l==0){
                l=i+1;
                continue;
            }

            if(a[i]!=b[i] and r==0){
                r=i+1;
                break;   
            }


        }

        cout<<r<<" "<<l<<endl;

        // cout<<((r)-(l))<<endl;
        
        
    }
    return 0;
}
