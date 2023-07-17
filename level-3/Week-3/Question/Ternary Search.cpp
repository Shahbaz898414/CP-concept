#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{

  auto f = [](double x) -> double
  {
    return -x * x + 4 * x + 5;
  };

  const double EPS = 1e-9;

  double l = 0, r = 1e9;
  while (r - l > EPS)
  {
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;

    if (f(m1) < f(m2))
      l = m1;
    else
      r = m2;
  }

  cout << f(l);

  return 0;
}
