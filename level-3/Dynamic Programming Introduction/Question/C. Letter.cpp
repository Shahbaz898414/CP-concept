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

  // ll k, a, b;
  // cin >> k >> a >> b;
  string s;

  long long kecil = 0, jwb = 0;
  cin >> s;
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] >= 'a' && s[i] <= 'z')
    {
      kecil++;
    }
    else
    {
      cout<<kecil<<" ";
      if (kecil > 0)
      {
        kecil--;
        jwb++;
      }
    }
  }

  cout<<endl;
  cout << jwb << endl;


}




/*

Today was my 59th day out of the 100 days  hard challenge.
So today, I solved 5 problems .


1. C. Constanze's Machine (https://codeforces.com/problemset/problem/1245/C).


2. D. Polycarp and Div 3 (https://codeforces.com/contest/1005/problem/D).


3. C. Basketball Exercise (https://codeforces.com/contest/1195/problem/C)


4. C. Letter (https://codeforces.com/contest/180/problem/C).


5. E. Anfisa the Monkey (https://codeforces.com/contest/44/problem/E).


#100dayschallenge #challenge #consistency #Cp #lessons  #learning
#competitiveprogramming


*/