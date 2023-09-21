#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const long long MOD = 1000000007;

vector<long long> ghnb(vector<long long> &A)
{
  if (A.size() == 1)
  {
    return A;
  }
  else
  {
    int N = A.size();
    int mid = N / 2;
    vector<long long> one(A.begin(), A.begin() + mid);
    vector<long long> two(A.begin() + mid, A.end());
    vector<long long> ans;
    ans.reserve(one.size() + two.size());




    ans.insert(ans.end(), ghnb(one).begin(), ghnb(one).end());
    ans.insert(ans.end(), ghnb(two).begin(), ghnb(two).end());
    return ans;
  }
}

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int N, L, R;
    cin >> N >> L >> R;
    vector<long long> ar;
    ar.reserve(pow(2, N));
    for (int i = 1; i <= pow(2, N); i++)
    {
      ar.push_back(i);
    }


    vector<long long> B = ghnb(ar);


    long long ans = 0;


    for (int i = L - 1; i < R; i++)
    {
      ans = (ans + B[i]) % MOD;
    }
    cout << ans << endl;
  }
  return 0;
}
