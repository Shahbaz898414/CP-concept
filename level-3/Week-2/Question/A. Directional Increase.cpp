#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{

    int t;cin>>t;

    while(t--) {
      ll n;cin>>n;

      ll p=0;
      vector<ll> arr(n+1);


      for (ll i =1; i <=n; i++)
      {
        /* code */
        cin>>arr[i];
        if(arr[i]) p=i;

        arr[i]+=arr[i-1];
      }

      if(arr[n])  cout<<"NO"<<endl;
      else{
        bool fl=1;
        for (ll i =1; i <p; i++)
        {
          /* code */
          if(arr[i]<=0) fl=0; 
        }


        if(fl)  cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
      }
      
    }

    return 0;
}

