#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define allElements(p) p.begin(), p.end()

#define fastIO()                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

int32_t main()
{
	fastIO();

	int testCases;
	cin >> testCases;
	while (testCases--)
	{
		ll n, k;
		cin >> n >> k;

		string s;
		cin >> s;

		// cout<<s<<" "<<k<<" "<<n<<endl;
		ll cnt = 0;
		for (int i = 0; i < (n - k); i++)
		{
			/* code */

			// cout<<i<<" ";
			if (s[i] != s[i + k] and i + k < n)
			{
				cnt += 1;
				s[i] = '1';
				s[i + k] = '1';
			}
		}

		ll o = 0;
		ll ze = 0;

		// for (int i = 0; i < n; i++)
		// {
		// 	if (s[i] == '0')
		// 		ze++;
		// 	else
		// 		o++;
		// }

		// if (o == 0 || ze == 0)
		// {
		// 	cout << cnt << endl;
		// }
		// else
		// {
		// 	// o = o % 2 + o / 2;

		// 	// ze = ze % 2 + ze / 2;

		// 	// cout<<endl;
		// 	// cout<<s<<endl;
		// 	cout << ze + cnt << endl;
		// }
	}

	return 0;
}
