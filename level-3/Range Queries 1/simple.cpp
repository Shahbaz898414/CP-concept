#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

#define ll long long
#define all(x) x.begin(), x.end()
#define vi vector<long long int>

using namespace std;






signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        ll n,k;cin>>n;

       if(n==2 || n==1){
        cout<<0<<endl;
       }else if(n==3){
        cout<<2<<endl;
       }else {

          ll sum=(n*(n+1))/2;

          if(sum&1) {
            cout<<0<<endl;
            continue;
          }

       }
    }

    return 0;
}





