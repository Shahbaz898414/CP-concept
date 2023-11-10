#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

// class SegTree
// {
// public:
//     const int N = 5000005;
//     int n; // array size
//     ll *sum_tree;
//     ll res = 0;

//     SegTree(vector<int> &arr, int n)
//     {
//         sum_tree = new ll[N];
//         this->n = n;
//         build(arr);
//     }

//     void build(vector<int> &arr)
//     {
//         for (int i = 0; i < n; ++i)
//         {
//             sum_tree[n + i] = arr[i];
//         }

//         for (int i = n - 1; i > 0; --i)
//         {
//             sum_tree[i] = sum_tree[i << 1] + sum_tree[i << 1 | 1];
//         }
//     }

//     void ans(int l, int r)
//     {
//         for (l += n, r += n; l < r; l >>= 1, r >>= 1)
//         {
//             if (l & 1)
//             {
//                 res = res + sum_tree[l++];
//             }

//             if (r & 1)
//             {
//                 res = res + sum_tree[--r];
//             }
//         }
//     }

//     ll getSum(int l, int r)
//     {
//         if (l > r)
//             return 0;
//         res = 0;
//         result(l, r);

//         return res;
//     }

//     void update(int p, ll value)
//     { // set value at position p
//         for (sum_tree[p += n] = value; p > 1; p >>= 1)
//         {
//             sum_tree[p >> 1] = (sum_tree[p] + sum_tree[p ^ 1]);
//         }
//     }
// };

void solve()
{

     ll array_size, subarray_size;
        cin >> array_size >> subarray_size;

        vector<ll> array_elements(array_size);

        for (auto &element : array_elements)
            cin >> element;

        ll left_index = 0;
        ll count_subarrays = 0;
        ll count_evens = 0, count_odds = 0;

        while (left_index < subarray_size) {
            if (array_elements[left_index] % 2 == 0)
                count_evens++;
            else
                count_odds++;

            left_index++;
        }

        if (count_odds > 0) {
            count_subarrays++;
        }

        for (ll right_index = 0; left_index < array_size; right_index++) {
            if (array_elements[right_index] % 2 == 0)
                count_evens--;
            else
                count_odds--;

            if (array_elements[left_index] % 2 == 0)
                count_evens++;
            else
                count_odds++;

            left_index++;

            if (count_odds > 0) {
                count_subarrays++;
            }
        }

        cout << count_subarrays << endl;

}

int main()
{

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

/*


Problem
You are given a directed tree with   N vertices. The edges are directed away from the root.

For each i=1,2,3,…,N, count the number of vertices that can possibly appear at the i-th position of a topological order of this tree.

That is, for each i, find the number of vertices   u such that there exists a topological order   T of the graph satisfying Ti = u.  

Input Format
The first line of input will contain a single integer T, denoting the number of test cases. Each test case consists of multiple lines of input. The first line of each test case contains one integer  N.

The next  N−1 lines describe the edges. The ith   of these   n−1 lines contains two space-separated integers    ui ​   and    vi ​, denoting a directed edge from    ui ​   to  vi ​.

Output Format
For each test case, output   N space-separated integers on a single line. The   i-th of them should be the answer for the   i-th position.  Constraints 1 ≤  ≤ 3000 1≤T≤3000 1 ≤  ≤ 1 0 5 1≤N≤10  5   1 ≤   ,   ≤  1≤u  i ​  ,v  i ​  ≤N The input graph is a directed tree on   N vertices. The sum of   N across all tests does not exceed  10^5 .


*/