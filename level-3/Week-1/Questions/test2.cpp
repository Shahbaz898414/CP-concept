#include <bits/stdc++.h>
#define ll long long
using namespace std;



int32_t main() {

    ll n, m;
    cin >> n >> m;
    ll arr[n];

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll t=0;

    for (ll i = 0; i < n-1; i++)
    {
        
        t=max(t,arr[i]-arr[i+1]-m);
    }

    cout<<t<<endl;
    
}

/*
string s;
    cin>>s;
    int n=s.size(),t=0;
    for(int i=0; i<n; i++)
    {
        int x=s.find("bear",i);
        if(x!=-1)
            t+=n-x-4+1;
    }
    cout<<t;
*/