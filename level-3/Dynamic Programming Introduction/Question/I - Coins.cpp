#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll inf=1e18;

int  main(){
   ll n;
   cin>>n;
   vector<double>arr(n);
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
    vector<double>dp(n+1,0);
    // dp  i repersent the number of head and it probabity of more head the i
    dp[0]=1;
 vector<double>prev_dp(n+1,0);
  prev_dp[0]=1;

        for(int i=1;i<=n;i++){
            
            for(int j=1;j<=i;j++){  //   i-1 use    we use to make j head 
                dp[j]=prev_dp[j-1]*arr[i-1]+prev_dp[j]*(1-arr[i-1]);
            }
            prev_dp=dp;
        }
      
  
    cout<<setprecision(10) <<dp[ceil(n/2.0)]<<endl;

   
}