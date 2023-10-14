#include <bits/stdc++.h>
using namespace std;

#define int long long


#define  all(x)  x.begin(), x.end()


const int N=4e5+5; int a[N],b[N],c[N],dp[N];

vector<pair<int,int>>  start[N];


vector<int>  temp;


class Solution {
public:


    int solve(int s,vector<int> &v1,vector<int> &v2,int mask,vector<int> &dp){
        if(s==v2.size()){
            return 0;
        }
        if(dp[mask]==INT_MAX){
            for(int j = 0; j < v1.size(); j++){
                if((mask&(1<<j))==0){
                    dp[mask] = min(dp[mask],(v1[s]^v2[j])+solve(s+1,v1,v2,mask+(1<<j),dp));
                }
            }
        }
        return dp[mask];
    }


    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int mask = 0;
        vector<int> dp(1<<14,INT_MAX);
        return solve(0,nums1,nums2,mask,dp);
    }


};



int main() {
  int t=1;
  // cin>>t;
  while(t--) {

  }
}