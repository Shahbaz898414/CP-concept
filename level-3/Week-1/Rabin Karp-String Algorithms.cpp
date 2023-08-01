#include <bits/stdc++.h>
using namespace std;

int p = 31;
const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

vector<long long> powers(N);

int main()
{

  string s;
  cin >> s;
  string t;
  cin >> t;

  int T = t.size();
  int S = s.size();
  powers[0] = 1;

  for (int i = 1; i < N; i++)
  {
    powers[i] = (powers[i - 1] * p) % MOD;
  }

  vector<long long> h(T + 1, 0);
  for (int i = 0; i < T; i++)
  
    h[i + 1] = (h[i] + (t[i] - 'a' + 1) * powers[i]) % MOD;
  

  // for(auto it:h){
  //   cout<<it<<" ";
  // }

  // cout<<endl;

  long long h_s = 0;

  for (int i = 0; i < S; i++)
    h_s = (h_s + (s[i] - 'a' + 1) * powers[i]) % MOD;
  

  vector<int> v;
  for (int i = 0; i + S - 1 < T; i++)
  {
    long long cur_h = (h[i + S] - h[i] + MOD) % MOD;
    if (cur_h == (h_s * powers[i]) % MOD)
    {
      // cout << "Found at index " << i + 1 << endl;

      v.push_back(i+1);
    }
  }

  for(auto it:v)  cout<<it<<" ";

  cout<<endl;
  return 0;
}
