#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int maxLengthNonDecreasing(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n + 1, 1e9 + 7);
    dp[0] = 0;
    int maxlen = 0;

    for (int& num : nums) {
        *upper_bound(dp.begin(), dp.end(), num) = num;
        maxlen = max(maxlen, int(upper_bound(dp.begin(), dp.end(), num) - dp.begin()));
    }

    return maxlen;
}

int main() {
    vector<int> nums = {5, 2, 2};
    cout << maxLengthNonDecreasing(nums) << endl;   // Output: 1

    nums = {1, 2, 3, 4};
    cout << maxLengthNonDecreasing(nums) << endl;   // Output: 4

    nums = {4, 3, 2, 6};
    cout << maxLengthNonDecreasing(nums) << endl;   // Output: 3

    return 0;
}



/*


int mainGFD(vector<int>&arr) 
    { 
        int n = arr.size(); 
        unordered_set<int> cnt; 
        int main = 0; 
        for (int i = 0; i < n; i++) 
            cnt.insert(arr[i]); 

             long long maxHGap = arr[0] - 1;
    for (int i = 1; i < arr.size(); ++i) {
        maxHGap = max(maxHGap, (long long)(arr[i] - arr[i - 1] - 1));
    }
    maxHGap = max(maxHGap, (long long)(n - arr.back()));
        for (int i = 0; i < n; i++) { 
            if (cnt.find(arr[i] - 1) != cnt.end()) { 
                continue; 
            } 
            else { 
                int j = arr[i]; 
                while (cnt.find(j) != cnt.end()) 
                    j++; 
                main = max(main, j - arr[i]); 
            } 
        } 
        return main; 
    } 
     
     
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) { 
        int x= mainGFD(hBars); 

         int a ,b,g=-1; 

             long long maxHGap = hBars[0] - 1;
        int y= mainGFD(vBars); 
       long long maxVGap = vBars[0] - 1;
        if(x==1 || y==1){ 
            return 4; 
        } 

         sort(hBars.begin(), hBars.end());
    sort(vBars.begin(), vBars.end());

 
    for (int i = 1; i < hBars.size(); ++i) {
        maxHGap = max(maxHGap, (long long)(hBars[i] - hBars[i - 1] - 1));
    }
    maxHGap = max(maxHGap, (long long)(n - hBars.back()));

    // Calculate the maximum gap between vertical bars
    
    for (int i = 1; i < vBars.size(); ++i) {
        maxVGap = max(maxVGap, (long long)(vBars[i] - vBars[i - 1] - 1));
    }
    maxVGap = max(maxVGap, (long long)(m - vBars.back()));


    int f= (maxHGap + 1) * (maxVGap + 1)*g;
        return max( min(x+1,y+1)* min(x+1,y+1),f); 
         
    }


*/
