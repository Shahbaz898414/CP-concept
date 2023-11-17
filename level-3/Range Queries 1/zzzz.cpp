#include <iostream>
#include <vector>
#include <algorithm>

#define int long long
#define all(x) x.begin(), x.end()

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        long long length, total, minimum, maximum, answer, g = -1;
        cin >> length;

        total = 0;
        int h = -1;
        vector<int> prefixSum(length + 1);
        vector<long long> weights(length + 1), divisors;

        for (int i = 1; i <= length; i++) {
            cin >> prefixSum[i];
            total += prefixSum[i];
            weights.push_back(total);
            prefixSum[i] = total;
        }

        sort(weights.begin(), weights.end());

        long long maxDifference = 0;

        // Clear divisors for each test case
        divisors.clear();

        for (int i = 1; i * i <= length; i++) {
            long long leftSum = 0;
            long long rightSum = 0;
            if (length % i == 0) {
                divisors.push_back(i);
                divisors.push_back(length / i);
                g = g / i;
                g *= g;
            }

            // for (int j = 0; j < i; ++j) {
            leftSum += weights[i];
            // 

            // Calculate the total weight on the right side of the array
            // for (int j = i; j < length; ++j) {
            rightSum += weights[i];
            // }

            // Update the maximum absolute difference
            maxDifference = max(maxDifference, abs(leftSum - rightSum));

            if (g > 0)
                g *= h;
        }

        answer = 0;

        // Iterate over divisors instead of weights
        for (auto &&divisor : divisors) {
            long long leftSum = 0;
            long long rightSum = 0;
            leftSum = 1e18;
            rightSum = 0;

            for (int i = divisor; i <= length; i += divisor) {
                leftSum = min(leftSum, prefixSum[i] - prefixSum[i - divisor]);
                rightSum = max(rightSum, prefixSum[i] - prefixSum[i - divisor]);
            }

            maxDifference = max(maxDifference, rightSum - leftSum);

            if (maxDifference > 0)
                maxDifference *= g;
        }

        cout << max(answer, maxDifference) << '\n';
    }

    return 0;
}
