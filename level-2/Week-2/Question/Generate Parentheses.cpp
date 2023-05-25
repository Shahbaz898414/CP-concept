#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<string> generateParenthesis(int n)
  {
    helper(n, 0, "");
    return mRes;
  }

  void helper(int n, int open, string s)
  {
    if (n == 0 && open == 0)
      mRes.push_back(s);

    if (n > 0)
      helper(n - 1, open + 1, s + "(");

    if (open > 0)
      helper(n, open - 1, s + ")");
  }

private:
  vector<string> mRes;
};

int main()
{
}