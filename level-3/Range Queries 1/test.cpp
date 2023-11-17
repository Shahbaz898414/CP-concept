// C++ program to show segment tree operations
// like construction, query and update
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define ll long long int



int maximumStrongPairXor(vector<int>& nums) {

  int len=nums.size();

  int mx=0;

  for (int i = 0; i < len; i++)
  {
    
    for (int j = 0; j < len; j++)
    {
      if(i!=j){
        if(abs(nums[i]-nums[j])<=min(nums[i],nums[j])){
          mx=max(mx,nums[i]^nums[j]);
        }
      }
    }
    
  }

  return mx;
  

}



vector<string> findHighAccessEmployees(vector<vector<string>>& ac) {
    vector<string>  vec;
    map<string,vector<string>> mp;

    for (int i = 0; i < ac.size(); i++)
    {
      /* code */
      mp[ac[i][0]].push_back(ac[i][1]);
    }
    


}



int main() {


	int t=1;
	cin >> t;

	while (t--) {

   int n;cin >> n;

        vector<long long> weights(n);
        for (int i = 0; i < n; ++i) {
            cin >> weights[i];
        }

        // Sort the weights in ascending order
        sort(weights.begin(), weights.end());

        cout<<weights[n-1]-weights[0]<<endl;

        long long maxDifference = 0;

        // // For each possible k, calculate the difference between the total weights of two trucks
        // for (int k = 1; k <= n; ++k) {
        //     long long leftSum = 0;
        //     long long rightSum = 0;

        //     // Calculate the total weight on the left side of the array
        //     for (int i = 0; i < k; ++i) {
        //         leftSum += weights[i];
        //     }

        //     // Calculate the total weight on the right side of the array
        //     for (int i = k; i < n; ++i) {
        //         rightSum += weights[i];
        //     }

        //     // Update the maximum absolute difference
        //     maxDifference = max(maxDifference, abs(leftSum - rightSum));
        // }

        // cout << maxDifference << endl;

   
    
    
		
  }
		return 0;
}

	

/*
Alex is participating in the filming of another video of BrMeast, and BrMeast asked Alex to prepare 250 thousand tons of TNT, but Alex didn't hear him well, so he prepared n  boxes and arranged them in a row waiting for trucks. The i -th box from the left weighs ai  tons.  All trucks that Alex is going to use hold the same number of boxes, denoted by k . Loading happens the following way:  The first k  boxes goes to the first truck, The second k  boxes goes to the second truck, ⋯ The last k  boxes goes to the nk -th truck. Upon loading is completed, each truck must have exactly k  boxes. In other words, if at some point it is not possible to load exactly k  boxes into the truck, then the loading option with that k  is not possible.  Alex hates justice, so he wants the maximum absolute difference between the total weights of two trucks to be as great as possible.  Alex has quite a lot of connections, so for every 1≤k≤n , he can find a company such that each of its trucks can hold exactly k  boxes. Print the maximum absolute difference between the total weights of any two trucks.  

Input The first line contains one integer t  (1≤t≤104 ) — the number of test cases.  The first line of each test case contains one integer n  (1≤n≤150000 ) — the number of boxes.  The second line contains n  integers a1,a2,…,an  (1≤ai≤109 ) — the weights of the boxes.  It is guaranteed that the sum of n  for all test cases does not exceed 150000 .

Output For each test case, print a single integer — the answer to the problem.


*/