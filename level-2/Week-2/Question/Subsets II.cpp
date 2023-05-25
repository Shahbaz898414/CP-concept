#include<bits/stdc++.h> 
using namespace std; 


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
    }
};




//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends



/*

class Solution {
private:

    void subset(int index,vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans){
        ans.push_back(ds);
        for(int i=index;i<nums.size();i++){
            if(i!=index && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            subset(i+1,nums,ds,ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        subset(0,nums,ds,ans);
        return ans;
    }
};


*/


/*

    Time complexity : O(2^N*2^N), For every index, we make 2 recursion calls and there are N elements and for
    every subset we are checking duplicates in output and in worst case it can contain 2^N-1 subset. so total time
    complexity is O(2^N*2^N).

    Space complexity : O(2^N*N), In worst case there can be 2^N-1 subsets and for every subset, we need O(N) 
    space on average so total space complexity is O(2^N*N).

    Solved using Array + Backtracking.

*/


/***************************************** Approach 1 *****************************************/

/*
class Solution {
private: 
    void subsetsWithDup(vector<int>& nums, vector<vector<int>> &output, vector<int> temp, int index) {
        if(nums.size() == index){
            bool isPresent = find(output.begin(), output.end(), temp) != output.end();
            if(!isPresent){
                output.push_back(temp);
            }
            return;
        }
        subsetsWithDup(nums, output, temp, index+1);
        temp.push_back(nums[index]);
        subsetsWithDup(nums, output, temp, index+1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> output;
        subsetsWithDup(nums, output, temp, 0);
        return output;
    }
};

*/




/*

    Time complexity : O(2^N).

    Space complexity : O(2^N*N), In worst case there can be 2^N-1 subsets and for every subset, we need O(N) 
    space on average so total space complexity is O(2^N*N).

    Solved using Array + Backtracking.

*/


/***************************************** Approach 2 *****************************************/


/*


class Solution {
public:
    void solve(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, int ind){
        ans.push_back(ds);
        for(int i=ind;i<nums.size();i++)
        {
            if(i>ind && nums[i] == nums[i-1]){
                continue;
            }
            ds.push_back(nums[i]);
            solve(nums,ds,ans,i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> ds;
        solve(nums,ds,ans,0);
        return ans;
    }
};

*/


/*


class Solution {
public:
    void solve(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, int ind)
    {
        ans.push_back(ds);
        for(int i =ind;i<nums.size();i++)
        {
            if(i>ind && nums[i] == nums[i-1])
            {
                continue;
            }

            ds.push_back(nums[i]);
            solve(nums,ds,ans,i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> ds;
        solve(nums,ds,ans,0);
        return ans;

    }
};

*/
