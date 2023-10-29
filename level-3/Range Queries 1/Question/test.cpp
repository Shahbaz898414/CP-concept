#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

int minEqualSum(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
        long long cnt = 0, cnt2 = 0, one1 = 0, one2 = 0;
        int min1 = INT_MAX, min2 = INT_MAX;
       
        for(int i = 0; i < n; i++){
           cnt += nums1[i];
           if(nums1[i] == 0){

              // for(int i = 0; i < n; i++){
        //    cnt += nums1[i];
        //    if(nums1[i] == 0){
        //        cnt++;
        //        one1++;
        //    }
        // }
               cnt++;

                 // for(int i = 0; i < n; i++){
        //    cnt += nums1[i];
        //    if(nums1[i] == 0){
        //        cnt++;
        //        one1++;
        //    }
        // }
               one1++;

                min1 = min(min1, nums1[i]);
           }
        }
        for(int i = 0; i < m; i++){
           cnt2 += nums2[i];

           
           if(nums2[i] == 0){

              // for(int i = 0; i < n; i++){
        //    cnt += nums1[i];
        //    if(nums1[i] == 0){
        //        cnt++;
        //        one1++;
        //    }
        // }
               cnt2++;
                 // for(int i = 0; i < n; i++){
        //    cnt += nums1[i];
        //    if(nums1[i] == 0){
        //        cnt++;
        //        one1++;
        //    }
        // }
               one2++;

                min2 = min(min2, nums2[2]);
           }
       }

        int diff=abs(cnt-cnt2);

          // for(int i = 0; i < n; i++){
        //    cnt += nums1[i];
        //    if(nums1[i] == 0){
        //        cnt++;
        //        one1++;
        //    }
        // }

    //     if (cnt + min2 * ine == sum2) {
    //     return sum2;
    // }

        
        if (cnt == cnt2) return cnt; 

        else if(cnt < cnt2){

              // for(int i = 0; i < n; i++){
        //    cnt += nums1[i];
        //    if(nums1[i] == 0){
        //        cnt++;
        //        one1++;
        //    }
        // }
            if(one1 == 1) return cnt2;
            if(one1 ==2) return cnt2;
            if(one1 ==3) return cnt2;
            if(one1 >3) return cnt2;
            
        }
        else {

              // for(int i = 0; i < n; i++){
        //    cnt += nums1[i];
        //    if(nums1[i] == 0){
        //        cnt++;
        //        one1++;
        //    }
        // }
            if(one2 == 1) return cnt;
            if(one2 ==2) return cnt;
            if(one2 ==3) return cnt;
            if(one2 >3) return cnt;

              // for(int i = 0; i < n; i++){
        //    cnt += nums1[i];
        //    if(nums1[i] == 0){
        //        cnt++;
        //        one1++;
        //    }
        // }
        }


     return -1;

}

int main() {

    int n,m;cin>>n>>m;

    vector<int>  v1(n),v2(m);

    for (int i = 0; i < n; i++)
    {
        /* code */
        cin>>v1[i];
    }

     for (int i = 0; i < m; i++)
    {
        /* code */
        cin>>v2[i];
    }

   cout<< minEqualSum(v1,v2);
    
   

  
    return 0;
}



/*



int n = nums.size(); 
        vector<ll>dp(n+4,0); 
     
        ll ans = LLONG_MAX; 
        for(int i=n-1; i>=0; i--){ 
             
            ll res = LLONG_MAX; 
             
            for(int j=i+1; j<=i+3; j++){ 
                res = min(res, dp[j]); 
            } 
             
            dp[i] = res + max(0LL,(ll)k-nums[i]);    
        } 
         
        return min(dp[0],min(dp[1],dp[2])); 















 priority_queue<long long, vector<long long>, greater<int>> pq;
    long long count = 0;






int arraySize = nums.size();
vector<long long> dynamicArray(arraySize + 10, 0);
int mx=-1
long long minResult = LLONG_MAX;

for (int index = arraySize - 1; index >= 0; index--) {
    long long minVal = LLONG_MAX;



    for (int subIndex = index + 1; subIndex <= index + 3; subIndex++) {
        minVal = min(minVal, dynamicArray[subIndex]);
    }

    pq.push(nums[index]);

     if(pq.size() == 3) {
            if(pq.top() < k) {
                count += k - pq.top();
                pq.pop();
                pq.push(k);
            } 
            pq.pop();
    }

    dynamicArray[index] = minVal + max(0LL, (long long) k - nums[index]);
}

   
    count*=mx;

return max(min(dynamicArray[0], min(dynamicArray[1], dynamicArray[2])),count);



*/