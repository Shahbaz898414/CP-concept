

#include <bits/stdc++.h>
using namespace std;


string s;
int a, b, c, d;
int main()
{

  
  cin >> s;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '(')
      a++;
    if (s[i] == ')')
      a--;
    if (s[i] == '#')
    {
      a--;
      b++;
    }
    if (a < 0)
    {
      cout << -1;
      return 0;
    }
  }


 //  //  //   cout<<a<<" "<<b<<endl;


  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '#')
    {
      c++;
      if (b == c)
        d -= a;
      d--;
    }
    if (s[i] == '(')
      d++;
    if (s[i] == ')')
      d--;
    if (d < 0)
    {
      cout << -1;
      return 0;
    }

  }



  for (int i = 1; i < b; i++)
    cout << 1 << endl;
  cout << a + 1;

  return 0;
}
