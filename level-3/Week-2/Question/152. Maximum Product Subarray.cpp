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
      if(nums[i] > 0) {
        if (v[i - 1] < 0)
          v[i] = nums[i];
        else if (!v[i - 1])
          v[i] = nums[i];
        else
          v[i] = nums[i] * v[i - 1];
      }else if (nums[i] < 0) {
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