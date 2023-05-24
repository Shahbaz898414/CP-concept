#include <bits/stdc++.h>
using namespace std;

//  class Solution {
//   public:
//     bool lovelyCards(int N, vector<int> &Cards) {
//         // code here
//     }
// };

int Sum(int n, int sum)
{

    if (n == 0)
        return sum;

    return n + Sum(n - 1, 0);
}

int32_t main()
{

    ll n, m;
    cin >> n >> m;
    ll arr[n];

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

