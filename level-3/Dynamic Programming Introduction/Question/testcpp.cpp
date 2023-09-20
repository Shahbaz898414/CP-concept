#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const long long MOD = 1000000007;

vector<long long> f(vector<long long> &A)
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
    vector<long long> result;
    result.reserve(one.size() + two.size());
    result.insert(result.end(), f(one).begin(), f(one).end());
    result.insert(result.end(), f(two).begin(), f(two).end());
    return result;
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
    vector<long long> A;
    A.reserve(pow(2, N));
    for (int i = 1; i <= pow(2, N); i++)
    {
      A.push_back(i);
    }
    vector<long long> B = f(A);
    long long result = 0;
    for (int i = L - 1; i < R; i++)
    {
      result = (result + B[i]) % MOD;
    }
    cout << result << endl;
  }
  return 0;
}
