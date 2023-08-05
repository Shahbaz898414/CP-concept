#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long long int

int main()
{

  
 string s, x;
	int k, a, b, ans = 0;
	cin >> s >> k;
	for(int i = 1; i <= k; i ++)
	{
		cin >> x;
		a = b = 0;
		for(int i = 0; i < s.size(); i ++)
		{
			if(s[i] == x[0]) a ++;
			else if(s[i] == x[1]) b ++;
			else
			{
				ans += min(a, b);
				a = b = 0;
			}
		}
		ans += min(a, b);
	}
	cout << ans << endl;


  return 0;
}
