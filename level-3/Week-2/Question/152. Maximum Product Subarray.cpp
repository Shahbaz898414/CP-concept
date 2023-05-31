#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    vector<int> v(nums.size(), 0);
    int odd = 0, oval;
    int till = 1, ans = nums[0];
    v[0] = nums[0];
    if (nums[0] < 0) {
      oval = 0;
      odd += 1;
    }

    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > 0) {
        if (v[i - 1] < 0)
          v[i] = nums[i];
        else if (!v[i - 1])
          v[i] = nums[i];
        else
          v[i] = nums[i] * v[i - 1];
      }
      else if (nums[i] < 0) {
        if (v[i - 1])
          v[i] = v[i - 1] * nums[i];
        else
          v[i] = nums[i];
        odd += 1;
        if (odd == 1)
          oval = i;
        else {
          if (odd % 2 == 0) {
            if (oval == i - 1)
              continue;
            v[i] *= v[oval];
          }
          else {
            v[i] /= v[oval];
          }
        }
      }
      else {
        v[i] = 0;
        odd = 0;
      }
    }


    for (int x : v)
      ans = max(ans, x); 
    return ans;
  }
};





/*


int maxProduct(vector<int>& arr) {

        int n = arr.size();

        int maxi = INT_MIN;

        int min_prod = 1;

        int max_prod = 1;

        for(int i = 0; i < n; i++)
        {
            int curr_prod_1 = max_prod * arr[i];

            int curr_prod_2 = min_prod * arr[i];

            max_prod = max({curr_prod_2, arr[i], curr_prod_1});

            min_prod = min({curr_prod_1, arr[i], curr_prod_2});

            maxi = max(maxi, max_prod);
        }

        return maxi;
}


*/



/*

class Solution {
public:

    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxi =1 , mini=1, res = INT_MIN;

        for(int i =0;i<n;i++){
            int temp = maxi; 
            maxi = max({nums[i], maxi*nums[i], mini*nums[i]});
            mini = min({nums[i], temp*nums[i], mini*nums[i]});

            res = max({maxi,mini,res});
        }
        return res;
    }


};



*/