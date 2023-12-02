#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = (10e8) + 7;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll k, a, b;
  cin >> k >> a >> b;

  string s;
  cin >> s;

  ll len = s.size();

  if (len < k * a || len > b * k)
  {
    cout << "No solution";
  }
  else
  {


    int l = 0, r = 0;
    cout<<len<<endl;


    while (k != 0) {


      r = (s.size() - l) / k;
     
      cout << s.substr(l, r) << endl;
      l += r;
      //  cout<<r<<" "<<k<<" "<<l<<endl;
      k--;
    }


  }
}

