#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void findNumbers(int N)
{

    if (N % 3 != 0)
    {

        cout << "-1\n";

        return;
    }

    int A = N / 3;

    int B = N / 3;

    int C = 1;

    cout << A << " " << B << " " << C << "\n";
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        ll n, m;
        cin >> n;
        string s;
        cin >> s;
        ll ans = 0;
        if (s.find('B') == -1)
            cout << "0\n";
        else
        {
            ll h = n - 1;
            while (s[h] == 'A')
                --h;
            ll pr = h;
            for (int i = h; i >= 0; --i)
            {
                if (s[i] == 'A')
                {
                    ans += pr - i;
                    pr = i;
                }
            }
            cout << ans << '\n';
        }
    }

    return 0;
}
