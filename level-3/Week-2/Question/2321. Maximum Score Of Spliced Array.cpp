#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
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

    int n=num1.size();

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

int main()
{
  ll t = 1;
  // cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    int len = s.size();
    vector<int> vec(26, -1);

    for (int i = 0; i < len; i++)
    {
      vec[s[i] - 'a'] = i;
    }

    string s1, s2;

    int i = 0;
    int cur = 0;

    while (i < len)
    {
      while (i <= vec[cur])
      {
        s1 += s[i];
        while (s1.size() and s1.back() - 'a' == cur)
        {
          s2 += s1.back();
          s1.pop_back();
        }

        i++;
      }

      cur++;

      while (s1.size() and s1.back() - 'a' <= cur)
      {
        s2 += s1.back();
        s1.pop_back();
      }
    }

    reverse(s1.begin(), s1.end());

    s2 += s1;

    cout << s2 << endl;
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
