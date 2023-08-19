#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, d;
        cin >> n >> m >> d;

        vector<int> sellers(m);
        for (int i = 0; i < m; i++) {
            cin >> sellers[i];
        }

        int min_cookies_with_sellers = m;
        int min_cookies_without_sellers = n;

        for (int i = 0; i < m; i++) {
            // Calculate cookies eaten with sellers
            int cookies_with_sellers = i + (n - sellers[m - i - 1]);

            // Calculate cookies eaten without this seller
            int cookies_without_seller = max(i, n - m);

            min_cookies_with_sellers = min(min_cookies_with_sellers, cookies_with_sellers);
            min_cookies_without_sellers = min(min_cookies_without_sellers, cookies_without_seller);
        }

        cout << min_cookies_with_sellers << " " << min_cookies_without_sellers << endl;
    }

    return 0;
}



/*




#include <bits/stdc++.h>

using namespace std;
#define int long long

int f(int x, int y, int d) {
    bool e = ((y - x) % d) == 0;
    return (y - x) / d + 1 - e;
}

signed main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, d;
        cin >> n >> m >> d;
        
        vector<int> arr(m);
        for (int i = 0; i < m; ++i) {
            cin >> arr[i];
        }
        
        int start = 0;
        if (arr[0] != 1) {
            start = 1;
            arr.insert(arr.begin(), 1);
        }

        
        arr.push_back(n + 1);
        n = arr.size();
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            ans += f(arr[i-1], arr[i], d);
        }
        int a2 = ans;
        int newans = ans;
        for (int i = 1; i < n-1; ++i) {
            int cur = f(arr[i-1], arr[i+1], d) - f(arr[i-1], arr[i], d) - f(arr[i], arr[i+1], d);
            newans = a2 + cur;
            ans = min(ans, newans);
        }
        int cnt = 0;
        for (int i = 1; i < n - 1; ++i) {
            int cur = f(arr[i-1], arr[i+1], d) - f(arr[i-1], arr[i], d) - f(arr[i], arr[i+1], d);
            newans = a2 + cur;
            if (newans == ans) cnt += 1;
        }
        if (ans == a2 && start == 0) {
            cnt += 1;
        }
        cout << ans << " " << cnt << endl;
    }

    return 0;
}



*/