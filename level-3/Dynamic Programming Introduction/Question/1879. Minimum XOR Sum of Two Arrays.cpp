#include <bits/stdc++.h>
using namespace std;

const int N = 5008;

int n;


int minimumXORSum(vector<int> &nums1, vector<int> &nums2)
{
  int n = nums1.size();

  int y=0,z=0;
  vector<vector<int>> dp(n, vector<int>((1 << n) + 1, 1e9));

  function<int(int, int)> solve = [&](int i, int mask)
  {
    if (i >= n)
      return 0;

    if (dp[i][mask] != 1e9)
      return dp[i][mask];
      cout<<z<<" z"<<endl;
      z++;
      

    for (int j = 0; j < n; j++)
    {
      /* code */
      if ((mask & (1 << j)) > 0)
      {
        // cout<<"cont"<<endl;
        continue;
      }

      // cout<<y<<" y"<<" "<<(mask & (1 << j))<<endl;y++;

      dp[i][mask] = min(dp[i][mask], (nums1[i] ^ nums2[j]) + solve(i + 1, mask | (i << j)));

      // cout<<dp[i][mask]<<"  dp[i][mask]"<<endl;
    }

    return dp[i][mask];


  };

  return solve(0, 0);
}

int main()
{


  cin>>n;

  vector<int> nums1(n);
  vector<int> nums2(n);

  for (int i = 0; i < n; i++)
  {
    /* code */
    cin>>nums1[i];
  }

  for (int i = 0; i < n; i++)
  {
    /* code */
    cin>>nums2[i];
  }


  

  cout<<minimumXORSum(nums1,nums2);


}




/*


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


*/


