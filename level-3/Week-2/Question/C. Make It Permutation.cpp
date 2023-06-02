#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define fe(i, a, b) for (int i = a; i <= b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)

void sort(vector<ll>& a) {
    sort(a.begin(), a.end());
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        ll n;
        ll c, d;
        
        cin >> n >> c >> d;

        vector<ll> a(n);
        f(i, 0, n) {
            cin >> a[i];
        }

        sort(a);

        ll ans = (a[0]-1);
        ll extra = 0;

        f(i, 1, n) {
            if (a[i] == a[i-1]) {
                extra++;
            }
            else {
                ans += (a[i]-a[i-1])-1;
            }
        }



        ans = ans*d;
        ans = ans + (extra*c);

        ans = min(ans, (n*c) + d);

        extra = 0;
        ll gap = (a[0]-1);
        ans = min(ans, gap*d + (n-1)*c);

        f(i, 1, n) {
            if (a[i] == a[i-1]) {
                extra++;
            }
            else {
                gap += (a[i]-a[i-1])-1;
                ans = min(ans, gap*d + (extra*c) + (n-1-i)*c);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}