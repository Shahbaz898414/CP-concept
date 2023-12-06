#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

long long gcd(long long a, long long b)
{
  while (b != 0)
  {
    long long temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

long long lcm(long long a, long long b)
{
  return (a / gcd(a, b)) * b;
}

void findABC(ll n)
{

  bool fl = 1;
  if (n % 3 != 0)
  {
    fl = 0;
  }
  ll a, b, c;

  a = n / 3;
  b = n / 3;
  c = 1;

  vector<ll> arr;

  ll i_value = 1;
  while (i_value < n - 1)
  {
    ll j_value = i_value;
    while (j_value < n - 1)
    {
      if (!((n - i_value) % (2 * j_value)))
      {

        if (a == 1 and b == i_value and c == (j_value * (n - i_value)) / (2 * j_value))
        {
          cout << 1 << " " << i_value << " " << (j_value * (n - i_value)) / (2 * j_value) << endl;
        }
        else if (c == 1 and b == (j_value * (n - i_value)) / (2 * j_value) and a == i_value)
        {
          cout << 1 << " " << i_value << " " << (j_value * (n - i_value)) / (2 * j_value) << endl;
        }
        else
          cout << 1 << " " << i_value << " " << (j_value * (n - i_value)) / (2 * j_value) << endl;

        // arr.push_back(1);
        // arr.push_back(i_value);
        // arr.push_back((j_value * (n - i_value)) / (2 * j_value));

        // for(auto it:arr)
        return;
      }

      // if(arr.size()>0){
      //   for(auto it:arr){
      //     cout<<it<<" ";
      //   }
      //   cout<<endl;
      // }

      return;

      j_value = 2 * j_value;
    }

    i_value = i_value * 2;
  }

  cout << -1 << endl;
}

int main()
{
  int num_tests;
  cin >> num_tests;

  for (int test_idx = 0; test_idx < num_tests; ++test_idx)
  {
    ll input_num;
    cin >> input_num;

    findABC(input_num);
  }

  return 0;
}
