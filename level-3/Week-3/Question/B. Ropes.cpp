/*


#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n,k; cin >> n>>k;
    vector<int> a(n);
    for(ll i = 0; i < n; i++) {
      
      
    }
   
    
}


*/



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canCutPieces(const vector<int>& ropes, int k, int len) {
    int count = 0;
    for (int rope : ropes) {
        count += rope / len;
    }
    return count >= k;
}

int findMaxLengthOfPieces(const vector<int>& ropes, int k) {
    int minLen = *min_element(ropes.begin(), ropes.end());
    int left = 1;
    int right = minLen;
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canCutPieces(ropes, k, mid)) {
            result = max(result, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> ropes(n);
    for (int i = 0; i < n; i++) {
        cin >> ropes[i];
    }

    int maxLength = findMaxLengthOfPieces(ropes, k);
    cout << maxLength << endl;

    return 0;
}
