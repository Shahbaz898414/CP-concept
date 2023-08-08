#include<bits/stdc++.h>
using namespace std;
#define ll long long


bool binary(vector<ll>  &a,ll mid,ll k,ll n){
   int cnt=0;

   for (int i = 0; i <n; i++) {
      int x=(mid/a[i]);
      cnt+=x;
      if(cnt>=k){
         return 1;
      }
   }
   
   return 0;
   
}


int main( ) {

   ll n,t;cin>>n>>t;
   vector<ll>  arr(n);
      // ll sum=0;

   for (ll i = 0; i < n; i++) {
      cin>>arr[i];
      // sum+=arr[i];
   }


   // ll itr=sum;
   ll l=0,r=1e18,ans=0;

   while(l<=r){
      ll mid=(l+r)/2;

      if(binary(arr,mid,t,n)){
         ans=mid;
         r=mid-1;
      }else {
         l=mid+1;
      }

   }

   cout<<ans<<endl;






    return 0;
}

