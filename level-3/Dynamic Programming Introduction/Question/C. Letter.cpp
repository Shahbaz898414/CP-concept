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

Today was my 58th day out of the 100 days  hard challenge.
So today, I solved 5 problems .


1. E - Unfair Sugoroku (https://lnkd.in/dmw-kQpm).


2. A. Halloumi Boxes (https://lnkd.in/dsU-9AUW).


3. B. StORage room (https://lnkd.in/dYAsrKAA)


4. C. Theofanis' Nightmare (https://lnkd.in/dmUDz3wy).


5. E. Anfisa the Monkey (https://lnkd.in/dtfHusss).


#100dayschallenge #challenge #consistency #Cp #lessons  #learning
#competitiveprogramming


*/