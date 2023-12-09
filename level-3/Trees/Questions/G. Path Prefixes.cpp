#include <bits/stdc++.h>

using namespace std;
#define int long long

const int maxn=2e5+5;
vector<int> ch[maxn];
int a[maxn];
int b[maxn];
int ans[maxn];
vector<int> vb;
int curb=0;
int cura=0;

void dfs(int x){
    curb+=b[x];
    cura+=a[x];
    vb.push_back(curb);
    ans[x]=upper_bound(vb.begin(),vb.end(),cura)-vb.begin();
    for(int v:ch[x]){
        dfs(v);
    }
    curb-=b[x];
    cura-=a[x];
    vb.pop_back();
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=0;i<n;++i) ch[i].clear();
        for(int i=1;i<n;++i){
            int pr,a1,b1;
            cin>>pr>>a1>>b1;
            --pr;
            ch[pr].push_back(i);
            a[i]=a1;
            b[i]=b1;
        }
        dfs(0);
        for(int i=1;i<n;++i) cout<<ans[i]-1<<' ';
        cout<<'\n';
    }
    return 0;
}


/*

You are given an integer array nums and an integer k.  The frequency of an element x is the number of times it occurs in an array.  An array is called good if the frequency of each element in this array is less than or equal to k.  Return the length of the longest good subarray of nums.  A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:  
Input: nums = [1,2,3,1,2,3,1,2], k = 2 Output: 6 Explanation: The longest possible good subarray is [1,2,3,1,2,3] since the values 1, 2, and 3 occur at most twice in this subarray. Note that the subarrays [2,3,1,2,3,1] and [3,1,2,3,1,2] are also good. It can be shown that there are no good subarrays with length more than 6. 
Example 2:
Input: nums = [1,2,1,2,1,2,1,2], k = 1 Output: 2 Explanation: The longest possible good subarray is [1,2] since the values 1 and 2 occur at most once in this subarray. Note that the subarray [2,1] is also good. It can be shown that there are no good subarrays with length more than 2. 
Example 3:  
Input: nums = [5,5,5,5,5,5,5], k = 4 Output: 4 Explanation: The longest possible good subarray is [5,5,5,5] since the value 5 occurs 4 times in this subarray. It can be shown that there are no good subarrays with length more than 4.    Constraints:  1 <= nums.length <= 105 1 <= nums[i] <= 109 1 <= k <= nums.length.



*/