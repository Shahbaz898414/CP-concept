#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
       int N;
        cin >> N;

        vector<int> B(N);
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }

        if (N % 2 != 0) {
            cout << -1 << endl;
            continue;
        }

        int M = N / 2;
        vector<int> A(N, 0);
        for (int i = 0; i < M; i++) {
            A[i] = B[i];
            if (i + M < N) {
                if (A[i] == B[i + M]) {
                    A[i + M] = 0;
                } else {
                    A[i + M] = abs(A[i] - B[i + M]);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            cout << A[i] << " ";
        }
        cout << endl;

        
    }

    return 0;
}









/*


Consider an array A of size N: A1 ,A2 ,…,AN ​  , where N is even. The AlterEgo of this array A, is another array B, which is computed as follows: 
1. Start with an empty array B. For i ranging from  1 1 to 2 2 N ​  , insert the elements     2 ) (A  i ​  +A  i+  2 N ​   ​  ) and     2 ∣ ∣A  i ​  −A  i+  2 N ​   ​  ∣ to the end of array B. Here   ∣ ∣x∣ refers to absolute value of x. Rearrange the array B in some random order. As you can see, because of the third point, an array A can have multiple AlterEgo arrays.  Given an array B of even length N, your job is to find if there exists an array A such that B is the AlterEgo of A. And if it does exist, find such an array A with the maximum possible sum of elements.  That is, if there is no array A such that B is an AlterEgo of A, print  − 1 −1. Else print an array A such that B is an AlterEgo of A, and the sum of the elements of this array A is as large as possible. If there are multiple arrays possible with the maximum sum, print any.  Input Format The first line of input will contain a single integer T, denoting the number of test cases. Each test case consists of two lines of input. The first line of each test case contains a single integer N — the number of elements in the array. The second line of each test case contains N space-separated integers 1  2 , …  B  1 ​  ,B  2 ​  ,…,B  N ​   — the elements of the array. Output Format For each test case, output on a new line, either  − 1 −1, or N space separated integers denoting array A. If there are multiple arrays possible with the maximum sum, print any.  Constraints 1  ≤ 1 0 5 1≤T≤10  5   1  ≤ 3 ⋅ 1 0 5 1≤N≤3⋅10  5  N is even. 1  ≤ 1 0 5 1≤B  i ​  ≤10  5   The sum of N over all test cases won't exceed  3 ⋅ 1 0 5 3⋅10  5  .











Consider an array A of size N: A1 ,A2 ,…,AN ​  , where N is even. The AlterEgo of this array A, is another array B, which is computed as follows: 
1. Start with an empty array B.
2. For i ranging from  1 to N/2 ​, insert the elements (A[i] ​  + A[i+ N/2]) and  | A[i] - A[i-N/2] | to the end of array B.
Here ∣x∣ refers to absolute value of x.
3.Rearrange the array B in some random order.

As you can see, because of the third point, an array A can have multiple AlterEgo arrays.
Given an array B of even length N, your job is to find if there exists an array A such that B is the AlterEgo of A. And if it does exist, find such an array A with the maximum possible sum of elements.  That is, if there is no array A such that B is an AlterEgo of A, print −1. Else print an array A such that B is an AlterEgo of A, and the sum of the elements of this array A is as large as possible. If there are multiple arrays possible with the maximum sum, print any.

Input 
Format The first line of input will contain a single integer  T, denoting the number of test cases. Each test case consists of two lines of input. The first line of each test case contains a single integer  N — the number of elements in the array. The second line of each test case contains  N space-separated integers  B1 ​,B2 ,…,BN  — the elements of the array.


Output Format For each test case, output on a new line, either  −1, or  N space separated integers denoting array  A. If there are multiple arrays possible with the maximum sum, print any.



*/