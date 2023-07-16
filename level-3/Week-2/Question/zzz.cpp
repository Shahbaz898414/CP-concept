/*

#include <bits/stdc++.h>
using namespace std;

void solve()
{
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        long long int arr[n + 1];
        vector<vector<long long int>> vex(k + 1);


         // long long int res = vex[i][0] / 2;
            // if (vex[i].size() >= 2)
            //     res = max(res, vex[i][1]);
        vector<long long int> brr(k + 1, 0);

        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        for (int i = 1; i <= n; i++)
        {
            vex[arr[i]].push_back(i - brr[arr[i]] - 1ll);

             // long long int res = vex[i][0] / 2;
            // if (vex[i].size() >= 2)
            //     res = max(res, vex[i][1]);
            brr[arr[i]] = i;
        }

        long long int bnv = INT_MAX;
        for (int i = 1; i <= k; i++)
        {
            vex[i].push_back(n - brr[i]);
             // long long int res = vex[i][0] / 2;
            // if (vex[i].size() >= 2)
            //     res = max(res, vex[i][1]);
            sort(vex[i].begin(), vex[i].end());
             // long long int res = vex[i][0] / 2;
            // if (vex[i].size() >= 2)
            //     res = max(res, vex[i][1]);
            reverse(vex[i].begin(), vex[i].end());
            long long int res = vex[i][0] / 2;

             // long long int res = vex[i][0] / 2;
            // if (vex[i].size() >= 2)
            //     res = max(res, vex[i][1]);
            if (vex[i].size() >= 2)

             // long long int res = vex[i][0] / 2;
            // if (vex[i].size() >= 2)
            //     res = max(res, vex[i][1]);
                res = max(res, vex[i][1]);

            bnv = min(bnv, res);

             // long long int res = vex[i][0] / 2;
            // if (vex[i].size() >= 2)
            //     res = max(res, vex[i][1]);
        }

        cout << bnv << endl;
    }
    return 0;
}
*/



/*

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minMaxPlanks(vector<int> &planks, int k)
{
    int n = planks.size();
    int ans = n;

    for (int i = 0; i < k; i++)
    {
        int left = 0, right = 0;
        int cnt = 0;

        while (right < n)
        {
            if (planks[right] == i)
            {
                cnt++;
                ans = min(ans, n - (right - left + 1) + cnt);
                right++;
            }
            else
            {
                if (cnt > 0)
                {
                    cnt--;
                    left++;
                }
                else
                {
                    left++;
                    right++;
                }
            }
        }
    }

    return ans;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> planks(n);
        for (int i = 0; i < n; i++)
        {
            cin >> planks[i];
        }

        int result = minMaxPlanks(planks, k);
        cout << result << endl;
    }

    return 0;
}
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canRearrange(vector<int>& A, vector<int>& B, vector<int>& C) {
    int n = A.size();
    vector<pair<int, int>> sortedPairs;
    
    for (int i = 0; i < n; i++) {
        sortedPairs.push_back(make_pair(max(A[i], B[i]), C[i]));
    }
    
    sort(sortedPairs.begin(), sortedPairs.end());
    
    for (int i = 0; i < n; i++) {
        int maxVal = sortedPairs[i].first;
        int targetVal = sortedPairs[i].second;
        
        if (A[i] != maxVal && B[i] != maxVal) {
            return false;
        }
        
        if (A[i] == maxVal && B[i] != targetVal) {
            swap(A[i], B[i]);
        } else if (B[i] == maxVal && A[i] != targetVal) {
            swap(A[i], B[i]);
        }
    }
    
    return true;
}

int main() {

    int t;cin>>t;

    while(t--){
         int n;
    cin >> n;
    
    vector<int> A(n), B(n), C(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }
    
    if (canRearrange(A, B, C)) {
        cout << "YES" << endl;
        // for (int i = 0; i < n; i++) {
        //     cout << A[i] << " ";
        // }
        // cout << endl;
        // for (int i = 0; i < n; i++) {
        //     cout << B[i] << " ";
        // }
        // cout << endl;
    } else {
        cout << "NO" << endl;
    }



    }
   
    
    return 0;
}
