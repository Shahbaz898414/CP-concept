#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

// using namespace std;

#define ll long long
typedef pair<ll, ll> II;
typedef vector<II> VII;
typedef vector<ll> VI;
typedef vector<VI> VVI;
// typedef long long ll;
#define PB push_back
#define F first
#define S second

int main(){
   int t=1;
   cin>>t;

   while(t--){
     int N, M;
        std::cin >> N >> M;
        std::vector<int> A(N);

        for (int i = 0; i < N; ++i) {
            std::cin >> A[i];
        }

        // Find the maximum element as the target value to match
        int maxElement = *max_element(A.begin(), A.end());
        long long operations = 0;

        // Calculate the number of operations needed
        for (int i = 0; i < N; ++i) {
            // Add the number of steps needed to raise A[i] to maxElement
            if (A[i] < maxElement) {
                operations += (maxElement - A[i] - 1) / M + 1;
            }
        }

        std::cout << operations << '\n';

		
		
    
   }
}


/*


You are given an array A of N elements and a positive integer M such that 1 < A[i] < N.

You can perform the following operation on A:

. Select at most M elements of A and increase all of the selected elements by 1.

Find the minimum number of operations required to make all elements of A equal.
It can be shown that for given constraints, it is always possible to make all elements of A equal using finite number of operations.

Input Format
. The first line of input contains a single integer T, denoting the number of test cases.
. Each test case consists of two lines of input.
o The first line of each test case contains two positive integers N and M - the length of the array A and maximum number of elements that you can select in each operation.
o The second line of each test case contains N space-separated integers A1, A2, ... , AN representing the array A.

Output Format
For each test case, output on a new line, the minimum number of operations required.

Constraints

. 1 ≤ T ≤ 10^5
· 1≤ N≤ 5x10^5
. 1≤ M ≤N
. 1< A[i] ≤ N
. The sum of N over all test cases won't exceed 5x 10^5.



*/