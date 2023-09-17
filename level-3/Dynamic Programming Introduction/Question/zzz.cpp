#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(ll n)
{
  ll temp = (n * (n + 1) / 2);
  if (temp % 2 == 1)
  {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  ll target = temp / 2;
  ll sum = 0;
  ll i = n;
  unordered_set<ll> s;
  s.reserve(n);
  while (sum < target)
  {
    s.insert(i);
    sum += i;
    /* cout << "Inserting " << i << " sum = " << sum << endl; */
    i--;
  }
  if (sum > target)
  {
    sum -= (i + 1);
    assert(sum < target);
    s.erase(s.find(i + 1));
    /* cout << "Removing " << i + 1 << " sum = " << sum << endl; */
    s.insert(target - sum);
    /* cout << "Inserting " << target - sum  << " sum = " << sum << endl; */
  }
  cout << s.size() << "\n";
  for (auto element : s)
  {
    cout << element << " ";
  }
  cout << "\n";
  cout << n - s.size() << "\n";
  for (int j = 1; j <= n; j++)
  {
    if (s.find(j) == s.end())
    {
      cout << j << " ";
    }
  }
  cout << "\n";
}

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll n, sum = 0;
  cin >> n;

  solve(n);

  // ll a[n+1];
  // a[0]=0;

  // for (int i = 1; i <=n; i++) {
  //   a[i]=i;
  //   sum+=i;
  // }

  // string ans="";
  // vector<int> v1,v2;

  // // cout<<sum<<endl;

  // if(sum%2==0){
  //   if(n%4==0){
  //     ans="YES";
  //     for (int i =1; i <n/4; i++) {
  //         v1.push_back(i);
  //     }

  //     for (int i = 0; i < n/4; i++)
  //     {
  //       /* code */
  //       v1.push_back(a[n-i]);
  //     }
  //     for (int i =n/4+1; i <v1[v1.size()-1]; i++)
  //     {
  //       /* code */
  //       v2.push_back(i);
  //     }

  //   }
  //     else if (n%4==3){
  //       vector<int> v;
  //       ans="YES";
  //       for (int i = 4; i <n+1; i++)
  //       {
  //         v.push_back(i);
  //       }
  //       v1.push_back(1);v1.push_back(2);
  //       v2.push_back(3);
  //       for (int i = 0; i <(n-3)/4; i++)
  //       {
  //         /* code */
  //         v1.push_back(v[i]);
  //         v1.push_back(v[v.size()-1-i]);
  //       }
  //       for (int i = 4+(n-3)/4; i <=n-(n-3)/4; i++)
  //       {
  //         /* code */
  //         v2.push_back(i);
  //       }

  //     }else{
  //       ans="NO";
  //     }
  // }else{
  //   ans="NO";
  // }

  // if(ans=="YES"){
  //   cout<<ans<<"\n";
  //   cout<<v1.size()<<endl;
  //   for (int i = 0; i <v1.size(); i++)
  //   {
  //     cout<<v1[0]<<" ";
  //   }
  //   cout<<endl;
  //   cout<<v2.size()<<endl;
  //   for (int i = 0; i < v2.size(); i++)
  //   {
  //     cout<<v2[i]<<" ";
  //   }

  // }else if(ans=="NO"){
  //   cout<<ans;
  // }

  return 0;
}