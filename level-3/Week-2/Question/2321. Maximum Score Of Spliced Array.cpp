#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
  int maxSubArraySum(vector<int>&a,vector<int> &b,int size){
    int mx1=0,mx2=0;

    for (int i = 0; i < size; i++) {
      mx2=mx2+a[i]+b[i];
      if(mx1<mx2){
        mx1=mx2;
      }

      if(mx2==0)
        mx2=0;
    }

    return mx1;
    
  }

  int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2)
  {

    int n=nums1.size();

    int sum1=0,sum2=0;


    for (int i = 0; i < n; i++) {
    
      sum1+=nums1[i];
      sum2+=nums2[i];

    }

    int ff = sum1+maxSubArraySum(nums2,nums1,n);
    int ss = sum2+maxSubArraySum(nums1,nums2,n);

    return max(ff,ss);
  }
};

int main() {
  ll t = 1;
  // cin >> t;
  while (t--) {
    
  }
}

/*

int score(vector<int>& a, vector<int>& b) {
    int runningSum = 0, maxi = 0;
    int sum = accumulate(a.begin(), a.end(), 0);

    for (int i = 0; i < a.size(); i++) {
        runningSum += b[i] - a[i];
        if (runningSum < 0)
            runningSum = 0;
        maxi = max(maxi, runningSum);
    }

    return sum + maxi;
}

int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
    return max(score(nums1, nums2), score(nums2, nums1));
}







*/
