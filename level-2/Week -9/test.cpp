#include <iostream>
#include <vector>
#include <cmath>

#include <bits/stdc++.h>

using namespace std;

int minTimeToVisitAllPlatforms(long long N, long long K, vector<long long>& A) {
    long long arr[100005];
arr[0]=A[0];
   for(int i=1;i<N;i++) {
      arr[i]=abs(arr[i-1]-A[i]);
   }

   for(int i=1;i<N;i++) {
      cout<<arr[i]<<" ";
   }
   cout<<endl;



}

int main() {
    int T;
    cin >> T;  // Number of test cases

    while (T--) {
        long long N, K;
        cin >> N >> K;  // Number of platforms and jump length

        vector<long long> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];  // Heights of platforms

        // int minTime = minTimeToVisitAllPlatforms(N, K, A);
        minTimeToVisitAllPlatforms(N, K, A);
        // cout << minTime << endl;
    }

    return 0;
}
