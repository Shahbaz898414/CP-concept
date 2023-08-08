#include<bits/stdc++.h>
using namespace std;
#define ll long long


bool binary(vector<int>  &a,int mid,int k,int n){
   int cnt=0;

   for (int i = 0; i <n; i++)
   {
      /* code */
      int x=mid/a[i];
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
      ll sum=0;

   for (ll i = 0; i < n; i++) {
      cin>>arr[i];
      // sum+=arr[i];
   }


   // ll itr=sum;
   ll l=0,r=n-1;



   
   






    return 0;
}

