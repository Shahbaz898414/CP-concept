#include <bits/stdc++.h>
#define ll long long
using namespace std;


class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        
    }
};

int main() {
  ll t=1; 
  // cin >> t;
  while (t--) {
    string s;cin>>s;
    int len=s.size();
    vector<int> vec(26,-1);

    for (int i = 0; i < len; i++) {
      vec[s[i]-'a']=i;
    }

    string s1,s2;

    int i=0;
    int cur=0;

    while(i<len) {
      while(i<=vec[cur]){
        s1+=s[i];
        while(s1.size() and s1.back()-'a'==cur){
          s2+=s1.back();    
          s1.pop_back();
        }

        i++;
      }

      cur++;

      while(s1.size() and s1.back()-'a' <=cur){
        s2+=s1.back();
        s1.pop_back();
      }
    }
    

    reverse(s1.begin(),s1.end());

    s2+=s1;

    cout<<s2<<endl;
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

