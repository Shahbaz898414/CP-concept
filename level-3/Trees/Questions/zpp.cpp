#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef long long LL;
#define PB push_back
#define F first
#define S second
#define ALL(a) a.begin(), a.end()
#define SET(a, b) memset(a, b, sizeof(a))
#define SZ(a) (int)(a.size())
#define FOR(i, a, b) for (int i = (a); i < (int)(b); ++i)
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define deb(a) cerr << #a << " = " << (a) << endl;
#define deb1(a)                                    \
    cerr << #a << " = [ ";                         \
    for (auto it = a.begin(); it != a.end(); it++) \
        cerr << *it << " ";                        \
    cerr << "]\n";
#define endl "\n"
const long long mod = 1e9 + 7;

auto find(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int ans = arr[1] - arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        ans = min(ans, arr[i] - arr[i - 1]);
    }
    return ans;
}

signed main()
{
    fast_io;
   
    int t = 1;
    cin >> t;
   while(t--)
    {
        

        int n,h=0;
        cin >> n;
        int k;
        cin >> k;
        vector<int> re(n);
        for (int i = 0; i < n; i++)
        {
            cin >> re.at(i);
        }

        if (k >= 3)
        {
            cout << 0 << endl;
            continue;
        }

        int ans = find(re);

        vector<int> dr(n,INT_MAX);

        sort(re.begin(), re.end());

        if (k == 1)
            cout << min({re[0], find(re)}) << endl;
        else
        {

            int y = n;

            for (int operation = 0; operation < k; ++operation)
            {

                auto maxElem = max_element(re.begin(), re.end());

                long long diff = *maxElem - accumulate(re.begin(), re.end(), 0LL) / y;

                dr.push_back(diff);

                y++;
            }

            int ans1 = find(re),ans2=y;



            sort(dr.begin(), dr.end());
             // if (ind < n && ind >= 0){
                    //     ans2 = min(ans2, abs(dr[ind] - gf));
                    //     ans1 = min(ans1, abs(re[ind] - main));
                    // }
                    // ind--;
                    // if (ind < n && ind >= 0){
                    //     ans2 = min(ans2, abs(dr[ind] - gf));
                    //     ans1 = min(ans1, abs(re[ind] - main));
                    // }
            sort(re.begin(), re.end());
            for (int i = 0; i < n; i++)
            {
                FOR(j, i + 1, n)
                {

                    int gf=abs(dr[i] - dr[j]);
                     // if (ind < n && ind >= 0){
                    //     ans2 = min(ans2, abs(dr[ind] - gf));
                    //     ans1 = min(ans1, abs(re[ind] - main));
                    // }
                    // ind--;
                    // if (ind < n && ind >= 0){
                    //     ans2 = min(ans2, abs(dr[ind] - gf));
                    //     ans1 = min(ans1, abs(re[ind] - main));
                    // }
                    

                    int main = abs(re[i] - re[j]);

                    int ind = lower_bound(re.begin(), re.end(), main) - re.begin();
                    // int idx=lower_bound(dr.begin(), dr.end(), gf) - re.begin();
                    if (ind < n && ind >= 0){
                        ans2 = min(ans2, abs(dr[ind] - gf));
                        ans1 = min(ans1, abs(re[ind] - main));
                    }
                    ind--;
                    if (ind < n && ind >= 0){
                        ans2 = min(ans2, abs(dr[ind] - gf));
                        ans1 = min(ans1, abs(re[ind] - main));
                    }
                }
            }

            cout << max(ans1 ,ans2*h)<< endl;
        }
    }
    return 0;
}



/*





*/