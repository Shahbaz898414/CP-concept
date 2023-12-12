#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9 + 7;

int main()
{

  ll n, k, ans = 0;

  string x;
  cin >> x;

  for (auto i : x)
    ans = (ans * 2 + i - '0') % mod;
  for (int i = 1; i < x.size(); i++)
    ans = (ans * 2) % mod;
  cout << ans;
}

/*


As a tradition, every year before IOI all the members of Natalia Fan Club are invited to Malek Dance Club
to have a fun night together. Malek Dance Club has 2^n members and coincidentally Natalia Fan Club also
has 2^n members. Each member of MDC is assigned a unique id i from 0 to 2^n - 1. The same holds for
each member of NFC.

One of the parts of this tradition is one by one dance, where each member of MDC dances with a member
of NFC. A dance pair is a pair of numbers (a, b) such that member a from MDC dances with member b
from NFC.

The complexity of a pairs' assignment is the number of pairs of dancing pairs (a, b) and (c, d) such that
a<c and b>d.

You are given a binary number of length n named x. We know that member i from MDC dances with
member i XOR x from NFC. Your task is to calculate the complexity of this assignment modulo
1000000007 (109+7).

Expression x XOR y denotes applying «XOR» to numbers x and y. This operation exists in all modern
programming languages, for example, in C++ and Java it denotes as «^», in Pascal - «xor».


Input
The first line of input contains a binary number x of lenght n, (1 ≤ n  ≤100).

This number may contain leading zeros.

Output
Print the complexity of the given dance assignent modulo 1000000007


*/

/*

Your task is to make a login signup app with node and react using mongodb
After logging in you have to show the username, email, phone number of the user also there would be a selection dropdown

Like when user selects the country he should only thn see the states and after selecting the state only he should see the city.

And you have to save those entries as well in the db.
You have to add 2FA for login.
And while signup otp on email needs to be done.
Email phone number should be validated and password should be atleast 8 characters.

*/