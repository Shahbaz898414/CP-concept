#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;



int numberOfGoodPartitions(vector<int> &nums)
{
    int n = nums.size();
    vector<long long> dp1(n + 1, 0);

    vector<int> arr;

    unordered_map<int, long long> dp;

    map<int, int> left;
    unordered_map<int, int> rightOccurrence;

    dp1[0] = 1;

    for (int i = 0; i < n; i++)
    {
        if (left.find(nums[i]) == left.end())
        {
            left[nums[i]] = i;
        }
        rightOccurrence[nums[i]] = i;
    }

    for (int i = 1; i <= n; ++i)
    {
        dp1[i] = (2 * dp1[i - 1]) % MOD;

        if (rightOccurrence[nums[i - 1]] != i - 1)
        {
            dp1[i] = (dp1[i] - dp1[rightOccurrence[nums[i - 1]]] + MOD) % MOD;
        }

        rightOccurrence[nums[i - 1]] = i - 1;
    }

    int j = 0, right = 0;
    for (int i = 0; i < n; i++)
    {
        right = max(right, rightOccurrence[nums[i]]);
        if (right == i)
        {
            arr.push_back(j);
            j = i + 1;
        }
    }

    long long gf = arr.size();
    long long cnt = 0, prev = 1;
    for (int i = 0; i < gf; i++)
    {
        cnt = prev % MOD;
        prev = (prev + cnt) % MOD;
    }

    return static_cast<int>(dp1[n] - 1);
}











int mod = 1000000007;
int numberOfGoodPartitions(vector<int> &nums)
{
    vector<int> arr;

    map<int, int> left, right;

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (left.find(nums[i]) == left.end())
        {
            left[nums[i]] = i;
        }
        right[nums[i]] = i;
    }

    int j = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        r = max(r, right[nums[i]]);
        if (r == i)
        {
            arr.push_back(j);
            j = i + 1;
        }
    }

    long long m = arr.size();
    long long ans = 0, prev = 1;
    for (int i = 0; i < m; i++)
    {
        ans = prev % mod;
        prev = (prev + ans) % mod;
    }
    return ans;
}

const int MOD = 1000000007;
int numberOfGoodPartitions(vector<int> &nums)
{

     int n = nums.size();
    vector<long long> dp1(n + 1, 0);

     vector<int> arr;
std::unordered_map<int, long long> dp;
    map<int, int> left, right;

    unordered_map<int, int> lastOccurrence;

    for (int i = 0; i < n; i++)
    {
        if (left.find(nums[i]) == left.end())
        {
            left[nums[i]] = i;
        }
        right[nums[i]] = i;
    }

    dp1[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp1[i] = (2 * dp1[i - 1]) % MOD;

        if (lastOccurrence.find(nums[i - 1]) != lastOccurrence.end()) {
            dp1[i] = (dp1[i] - dp1[lastOccurrence[nums[i - 1]] - 1] + MOD) % MOD;
        }

        lastOccurrence[nums[i - 1]] = i;
    }


    int j = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        r = max(r, right[nums[i]]);
        if (r == i)
        {
            arr.push_back(j);
            j = i + 1;
        }
    }


     long long result = 0;
  long long sum = 0;

   for (int i = 0; i < n; ++i) {
    dp[nums[i]] = (dp[nums[i]] + sum + 1) % MOD;
    sum = (sum + dp[nums[i]]) % MOD;
  }



    long long m = arr.size(),h=0;
    long long ans = 0, prev = 1;
    for (int i = 0; i < m; i++)
    {
        ans = prev % mod;
        prev = (prev + ans) % mod;
    }



    for (auto &pair : dp) {
        result = (result + pair.second) % MOD;
    }
        result*=h;

    return max(ans,result);

    


}

long long countSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();
    long long result = 0;
    std::stack<int> st;
    std::vector<int> right(n, n);

    long long mx1 = 0;
    for (auto ti : nums)
        mx1 = max(mx1, (long long)ti);

    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && nums[i] > nums[st.top()])
        {
            right[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    long long ans = 0, h = 0;

    int i = 0, main = 0;
    bool fl = false;

    while (!st.empty())
        st.pop();

    int index = 0;

    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] == mx1)
        {
            main++;
        }

        while (main == k)
        {
            fl = true;
            if (nums[i] == mx1)
                main--;
            i++;
        }

        if (fl)
        {
            ans += (i);
        }
    }

    while (index < n)
    {
        int j = right[index];
        int count = 0;
        while (index < j)
        {
            int dup = 1;
            while (index + 1 < j && nums[index] == nums[index + 1])
            {
                ++index;
                ++dup;
            }
            count += dup;
            ++index;
        }
        if (count >= k)
        {
            result += n - j;
        }
        else
        {
            index = j;
        }
    }

    return max(ans, h * result);
}

int main()
{

    cout << pow(2, 3) << endl;
    // // Example 1
    // vector<vector<int>> variables1 = {{2, 3, 3, 10}, {3, 3, 3, 1}, {6, 1, 1, 4}};
    // int target1 = 2;
    // vector<int> result1 = findGoodIndices(variables1, target1);
    // cout << "Example 1 Output: [";
    // for (int i = 0; i < result1.size(); ++i) {
    //     cout << result1[i];
    //     if (i < result1.size() - 1) {
    //         cout << ", ";
    //     }
    // }
    // cout << "]" << endl;

    // // Example 2
    // vector<vector<int>> variables2 = {{39, 3, 1000, 1000}};
    // int target2 = 17;
    // vector<int> result2 = findGoodIndices(variables2, target2);
    // cout << "Example 2 Output: [";
    // for (int i = 0; i < result2.size(); ++i) {
    //     cout << result2[i];
    //     if (i < result2.size() - 1) {
    //         cout << ", ";
    //     }
    // }
    // cout << "]" << endl;

    return 0;
}


/*


mujhe bure logo se nafrat hai wo khud ko sabse behtar samjhte hai
jab ki unme akal aur insaaniyat dono ek dam na ke barabar hoti

magar achhe log aur bure hote hai kyuki wo un bure logo ko maaf kar dete  hai or  unhe lagta hai ki unhone koi mahan kaam kiya hai

Aisi chijo se mera dimaag  kharab ho jata hai

*/