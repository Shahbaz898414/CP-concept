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
    while (k != 0)
    {
      r = (s.size() - l) / k;
      cout << s.substr(l, r) << endl;
      l += r;
      k--;
    }
  }
}

/*


#include<bits/stdc++.h>
using namespace std;
int k,a,b,l,r,len;
string s;
int main(){
  cin >> k >> a >> b >> s;
  len=s.size();
  if (s.size()<(k*a) || s.size()>(k*b))
    return cout << "No solution",0;
  for(;k>0;k--){
    r=(s.size()-l)/k;
    cout << s.substr(l,r) << endl;
    l+=r;
  }
}








#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int k, a, b;
  string s;
  cin >> k >> a >> b >> s;
  int n = s.size();
  if (k*a > n || k*b < n) {
    cout << "No solution" << endl;
  } else {
    for (int i = 0; i < k; i++) {
      cout << s.substr(i*n/k,(i+1)*n/k-i*n/k) << endl;
    }
  }
}



*/