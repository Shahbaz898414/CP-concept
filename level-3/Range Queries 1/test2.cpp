#include <iostream>
#include <vector>
#include <climits>

#include <bits/stdc++.h>

using namespace std;

long long gfv(vector<long long>& arr, int left, int right) {

  int previous = 0;
    int h=-1;
    long long evenSum = arr[0];
   
    long long maxSoFar = LLONG_MIN;
     long long oddSum = 0;
    long long ans = LLONG_MIN;
    long long  maxEndingHere = 0;

    for (int i = left; i <= right; i++) {
        maxEndingHere = maxEndingHere + arr[i];
        if (maxSoFar < maxEndingHere)
            maxSoFar = maxEndingHere;

        if (maxEndingHere < 0)
            maxEndingHere = 0;
    }
    return maxSoFar;
}

void solve() {
        int testCases;
    cin >> testCases;

    while (testCases--) {

      long long length;
        cin >> length;
       
        vector<long long> prefixSum(length + 1); 

         vector<long long> weights(length),divisors;

        long long total, minimum, maximum, answer;
   total = 0;
        for (int i = 1; i <= length; i++) {
            cin >> prefixSum[i];
            weights.push_back(prefixSum[i]);
            total += prefixSum[i];
            prefixSum[i] = total;
        }


        sort(weights.begin(), weights.end());

        long long maxDifference = 0;

        for (int k = 1; k * k <= length; k++) {
           long long leftSum = 0;
            long long rightSum = 0;
            if (length % k == 0) {
                divisors.push_back(k);
                divisors.push_back(length / k);
            }
            // for (int i = 0; i < k; ++i) {
                leftSum += weights[k];
            // }

            // Calculate the total weight on the right side of the array
            // for (int i = k; i < length; ++i) {
                rightSum += weights[k];
            // }

            // Update the maximum absolute difference
            maxDifference = max(maxDifference, abs(leftSum - rightSum));
        }

        answer = 0;

        for (auto &&divisor : divisors) {
            minimum = 1e18;
             
            maximum = 0;

            for (int i = divisor; i <= length; i += divisor) {
                minimum = min(minimum, prefixSum[i] - prefixSum[i - divisor]);
                // leftSum += weights[i];
                maximum = max(maximum, prefixSum[i] - prefixSum[i - divisor]);
            }

            answer = max(answer, maximum - minimum);
        }

        cout << answer << '\n';
    }





    
}

int main() {
  int t;cin>>t;
  while(t--)
    solve();
    return 0;
}
