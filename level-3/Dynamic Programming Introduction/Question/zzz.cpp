#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define allElements(p) p.begin(), p.end()

#define fastIO()                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

/*



	 vector<string> ans;

    for (int i = 1; i < n; ++i) {
        
        if (groups[i] != groups[i - 1] && words[i].size() == words[i - 1].size()) {
            int fd = 0;
            for (size_t j = 0; j < words[i].size(); ++j) {
                if (words[i][j] != words[i - 1][j]) {
                    fd++;
                }
            }
            if (fd == 1) {
                ans.push_back(words[i]);
            }
        }
    }


    ans.insert(ans.begin(), words[0]);



*/

vector<string> getsInLongestSubsequence(int n, vector<string> &s, vector<int> &vec)
{
	vector<string> ans;
	vector<string> main;

	int fg = 0, sum = 0, a = 0, b = 0;

	for (int i = 1; i < n; ++i)
	{

		if (vec[i] != vec[i - 1] && s[i].size() == s[i - 1].size())
		{
			fg = 0,b=0;

			sum += abs(vec[i] - vec[i - 1]);

			for (int j = 0; j < s[i].size(); ++j)
			{
				if (s[i][j] != s[i - 1][j])
				{
					fg++;
				}else {

					b++;
				}
			}
			if (fg == 1)
			{
				ans.push_back(s[i]);

				a++;

				main.push_back(s[i]);
			}
		}

		if (a > fg || b>fg) {
			sum = sum / 2;
		}
	}



	ans.insert(ans.begin(), s[0]);

	main.insert(main.begin(),s[0]);

	if(ans.size()<=0)  return main;

	return ans;


}

int32_t main()
{
	// fastIO();

	int n;
	cin >> n;
	vector<string> ss(n);

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		ss.push_back(s);
	}

	// lastVisitedIntegers(ss);

	return 0;
}
